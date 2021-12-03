/*
* Ibrahim Khan
* CS 4220-001
* Project 1: Program 2
* 03/15/2021
* This program converts a bit stream into a frame by CRC. The program takes two inputs
* from the user. The first input is the bit stream and the second input is the generator
* function in binary form. The user also inputs the lengths of each input beforehand.
* Then, the program does polynomial division to display the bit stream that should be
* transmitted.
*/

#include <stdio.h>

int main (int argc, char * argv[]) {
	
	//Declaring variables
	int streamLength, generatorLength;
	
	//Getting length of input bit stream
	printf("Enter the length of your bit stream: ");
	scanf("%d", &streamLength);
	
	//Loop makes sure length of input bit stream is between 8 and 128 bits
	while (streamLength < 8 || streamLength > 128) {
		printf("ERROR! The bit stream must be between 8 and 128 bits.\n");
		printf("Enter the length of your bit stream: ");
		scanf("%d", &streamLength);
	}
	
	//Getting length of generator function
	printf("Enter the length of your generator function: ");
	scanf("%d", &generatorLength);
	
	//Loop makes sure length of generator function is between 4 and 16 bits
	while (generatorLength < 4 || generatorLength > 16) {
		printf("ERROR! The generator function must be between 4 and 16 bits.\n");
		printf("Enter the length of your bit stream: ");
		scanf("%d", &generatorLength);
	}
	
	int bitStream[streamLength + (generatorLength - 1)]; //Input bit stream declared
	int generator[generatorLength]; //Generator function declared
	int remainder[generatorLength]; //Array to track the remainder during division
	
	printf("\nEnter each bit of the input bit stream.\n"); //User will know which bits to input
	
	//Loop adds bits to input bit stream
	for (int i = 0; i < sizeof(bitStream)/4; i++) {
		
		static int tempBit; //Variable to temporarily store user input
		static int tempIndex = 1; //Variable to track number of user inputs
		
		//Collect user input
		if (i < streamLength) {	
			printf("Enter bit #%d: ", tempIndex); //User prompted to enter next data bit
			scanf("%d", &tempBit);
			
			//Loop makes sure bits are either 0 or 1
			while (tempBit < 0 || tempBit > 1) {
				printf("ERROR! Bits can only be 0 or 1.\n");
				printf("Enter bit #%d: ", tempIndex);
				scanf("%d", &tempBit);
			}
			
			bitStream[i] = tempBit; //Add bit to input bit stream
			tempIndex++;
		}
		//Add additional zeroes based on generator length (number of zeroes = degree of generator - 1)
		else {
			bitStream[i] = 0;
		}
	}
	
	printf("\nEnter each bit of the generator function.\n"); //User will know which bits to input
	
	//Loop collects bits from user and adds to generator array
	for (int i = 0; i < sizeof(generator)/4; i++) {
		
		static int tempBit; //Variable to temporarily store user input
		static int tempIndex = 1; //Variable to track number of user inputs
		
		printf("Enter bit #%d: ", tempIndex); //User prompted to enter next data bit
		scanf("%d", &tempBit);
			
		//Loop makes sure bits are either 0 or 1
		while (tempBit < 0 || tempBit > 1) {
			printf("ERROR! Bits can only be 0 or 1.\n");
			printf("Enter bit #%d: ", tempIndex);
			scanf("%d", &tempBit);
		}
		
		generator[i] = tempBit; //Add bit to input bit stream
		tempIndex++;
	}
	
	//Loop adds bits from bitStream to remainder until remainder cannot hold anymore bits
	for (int i = 0; i < generatorLength; i++) {
		remainder[i] = bitStream[i];
	}
	
	//Loop runs until all XOR calculations have been performed
	for (int i = 0; i < streamLength; i++) {
		
		static int bitIterator = 1; //Used to keep track of which bit needs to be brought down
		
		//If XOR is done using generator
		if (remainder[0] == 1) {
			
			//Loop runs until all bits in remainder have been updated
			for (int j = 0; j < generatorLength; j++) {
				//Last bit to be updated
				if (j == generatorLength - 1) {
					remainder[j] = bitStream[j+bitIterator];
					bitIterator++;
				}
				//To update all other bits
				else {
					remainder[j] = remainder[j+1]^generator[j+1];
				}
			}
		}
		//If XOR is done using 0
		else {
			
			//Loop runs until all bits in remainder have been updated
			for (int j = 0; j < generatorLength; j++) {
				//Last bit to be updated
				if (j == generatorLength - 1) {
					remainder[j] = bitStream[j+bitIterator];
					bitIterator++;
				}
				//To update all other bits
				else {
					remainder[j] = remainder[j+1]^0;
				}
			}
		}
	}
	
	//Loop changes the extra zeroes in bitStream to the remainder
	for (int i = streamLength; i < sizeof(bitStream)/4; i++) {
		static int remainderIterator = 0; //Keep track of bits in remainder
		
		bitStream[i] = remainder[remainderIterator]; //Replace zero with bit from remainder
		remainderIterator++;
	}
	
	//Displaying output
	printf("\nOutput: ");
	for (int i = 0; i < sizeof(bitStream)/4; i++) {
		printf("%d",bitStream[i]);
	}
	
}
