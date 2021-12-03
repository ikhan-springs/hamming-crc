/*
* Ibrahim Khan
* CS 4220-001
* Project 1: Program 1.1
* 03/15/2021
* This program converts a message bit stream into a frame by Hamming code. The user is first asked for
* the length of the bit stream and then the program asks for each bit in the message one by one. This
* program is designed to handle bit streams between 1 and 64 bits.
*/

#include <stdio.h>

int getNumRedundancyBits (int);
void calculateParityBits (int, int, int[]);

int main (int argc, char * argv[]) {
	
	//Declaring variables
	int numBits, numRedundancyBits;
	
	//Getting length of input bit stream
	printf("Enter the length of your bit stream: ");
	scanf("%d", &numBits);
	
	//Loop makes sure length of input bit stream is between 1 and 64 bits
	while (numBits < 1 || numBits > 64) {
		printf("ERROR! The bit stream can only be between 1 and 64 bits.\n");
		printf("Enter the length of your bit stream: ");
		scanf("%d", &numBits);
	}
	
	numRedundancyBits = getNumRedundancyBits(numBits); //Calculating number of redundancy bits
	
	int bitStream[numBits + numRedundancyBits]; //Output bit stream declared
	
	//Loop adds bits to output bit stream
	for (int i = 0; i < numBits+numRedundancyBits; i++) {
		
		static int tempBit; //Variable to temporarily store user input
		static int tempIndex = 1; //Variable to track number of user inputs
		
		//Adding a placeholder for check bit
		if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15 || i == 31 || i == 63) {
			bitStream[i] = 0;
		}
		//Adding a data bit
		else {
			printf("Enter bit #%d: ", tempIndex); //User prompted to enter next data bit
			scanf("%d", &tempBit);
			
			//Loop makes sure bits are either 0 or 1
			while (tempBit < 0 || tempBit > 1) {
				printf("ERROR! Bits can only be 0 or 1.\n");
				printf("Enter bit #%d: ", tempIndex);
				scanf("%d", &tempBit);
			}
			
			bitStream[i] = tempBit; //Add bit to output frame
			tempIndex++;
		}
	}
	
	calculateParityBits (numBits, numRedundancyBits, bitStream); //Parity bits are changed appropriately
	
	//Displaying output frame
	printf("\nOutput: ");
	for (int i = 0; i < numBits+numRedundancyBits; i++) {
		printf("%d",bitStream[i]);
	}
	
	return 0;
} //main

//Function returns the number of redundancy bits
int getNumRedundancyBits (int numBits) {
	
	if (numBits == 1) {
		return 2;
	}
	else if (numBits <= 4) {
		return 3;
	}
	else if (numBits <= 11) {
		return 4;
	}
	else if (numBits <= 26) {
		return 5;
	}
	else if (numBits <= 57) {
		return 6;
	}
	else {
		return 7;
	}
} //getNumRedundancyBits

//Function switches parity bits to 1 if necessary
//Before function, the bit stream's parity bits are all zeroes
void calculateParityBits (int numBits, int numRedundancyBits, int bitStream[]) {
	
	//Declaring function variables
	int numOfOnes, startIndex, check;
	
	//Loop checks every check bit
	for (int i = 1; i <= numRedundancyBits; i++) {
		
		numOfOnes = 0; //Used to calculate parity
		check = 1; //Used to consider which bits are used for parity calculation
		
		//First check bit
		if (i == 1) {
			for (startIndex = 0; startIndex < numBits+numRedundancyBits; startIndex += 2) {
				if (bitStream[startIndex] == 1) {
					numOfOnes++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[0] = 1;
			}
		}
		
		//Second check bit
		else if (i == 2) {
			for (startIndex = 0; startIndex < numBits+numRedundancyBits; startIndex++) {
				
				if (check > 0 && bitStream[startIndex] == 1) {
						numOfOnes++;
				}
				
				if (check == 2) {
					check = -1;
				}
				else {
					check++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[1] = 1;
			}
		}
		//Third check bit
		else if (i == 3) {
			for (startIndex = 3; startIndex < numBits+numRedundancyBits; startIndex++) {
				
				if (check > 0 && bitStream[startIndex] == 1) {
						numOfOnes++;
				}
				
				if (check == 4) {
					check = -3;
				}
				else {
					check++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[3] = 1;
			}
		}
		//Fourth check bit
		else if (i == 4) {
			for (startIndex = 7; startIndex < numBits+numRedundancyBits; startIndex++) {
				
				if (check > 0 && bitStream[startIndex] == 1) {
						numOfOnes++;
				}
				
				if (check == 8) {
					check = -7;
				}
				else {
					check++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[7] = 1;
			}
		}
		//Fifth check bit
		else if (i == 5) {
			for (startIndex = 15; startIndex < numBits+numRedundancyBits; startIndex++) {
				
				if (check > 0 && bitStream[startIndex] == 1) {
						numOfOnes++;
				}
				
				if (check == 16) {
					check = -15;
				}
				else {
					check++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[15] = 1;
			}
		}
		//Sixth check bit
		else if (i == 6) {
			for (startIndex = 31; startIndex < numBits+numRedundancyBits; startIndex++) {
				
				if (check > 0 && bitStream[startIndex] == 1) {
						numOfOnes++;
				}
				
				if (check == 32) {
					check = -31;
				}
				else {
					check++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[31] = 1;
			}
		}
		//Seventh check bit
		else {
			for (startIndex = 63; startIndex < numBits+numRedundancyBits; startIndex++) {
				
				if (check > 0 && bitStream[startIndex] == 1) {
						numOfOnes++;
				}
				
				if (check == 64) {
					check = -63;
				}
				else {
					check++;
				}
			}
			
			if (numOfOnes%2 != 0) {
				bitStream[63] = 1;
			}
		}
	}
} //calculateParityBits
