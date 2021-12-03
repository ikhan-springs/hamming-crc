/*
* Ibrahim Khan
* CS 4220-001
* Project 1: Program 1.2
* 03/15/2021
* This program corrects single-bit errors in a frame and outputs the data bits by using Hamming
* coding. The user is first asked for the length of the bit stream and then the program asks
* for each bit in the message one by one. This program is designed to handle input bit streams
* between 3 and 71 bits.
*/

#include <stdio.h>

int getNumRedundancyBits(int);
void checkParityBits (int, int, int[]);
void errorCorrector(int[], int[]);

int main (int argc, char * argv[]) {
	
	//Declaring variables
	int numBits, numRedundancyBits;
	
	//Getting length of input bit stream
	printf("Enter the length of your bit stream: ");
	scanf("%d", &numBits);
	
	//Loop makes sure length of input bit stream is between 3 and 71 bits
	while (numBits < 3 || numBits > 71) {
		printf("ERROR! The bit stream must be between 3 and 71 bits.\n");
		printf("Enter the length of your bit stream: ");
		scanf("%d", &numBits);
	}
	
	int bitStream[numBits]; //Input bit stream declared
	
	//Loop collects bits from user and adds to input bit stream
	for (int i = 0; i < numBits; i++) {
		
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
		
		bitStream[i] = tempBit; //Add bit to input bit stream
		tempIndex++;
	}
	
	numRedundancyBits = getNumRedundancyBits(numBits); //Calculating number of redundancy bits
	
	checkParityBits(numBits, numRedundancyBits, bitStream); //Checking for errors
	
	//Displaying output stream
	printf("\nOutput: ");
	for (int i = 0; i < sizeof(bitStream)/4; i++) {
		switch (i) {
			case 0:
			case 1:
			case 3:
			case 7:
			case 15:
			case 31:
			case 63: break;
			default: printf("%d",bitStream[i]);
		}
	}
	
	return 0;
} //main

//Function returns the number of redundancy bits
int getNumRedundancyBits (int numBits) {
	
	if (numBits == 3) {
		return 2;
	}
	else if (numBits <= 7) {
		return 3;
	}
	else if (numBits <= 15) {
		return 4;
	}
	else if (numBits <= 31) {
		return 5;
	}
	else if (numBits <= 63) {
		return 6;
	}
	else {
		return 7;
	}
} //getNumRedundancyBits

//Function calculates parity bits and makes sure stream check bits are correct
void checkParityBits (int numBits, int numRedundancyBits, int bitStream[]) {
	
	//Declaring function variables
	int tempVar, parity;
	int errors[] = {0,0,0,0,0,0,0}; //Array keeps track of any parity bit errors found
	
	//Loop checks every parity bit
	for (int i = 1; i <= numRedundancyBits; i++) {
		
		//First check bit
		if (i == 1) {
			tempVar = 3; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 3: parity = bitStream[tempVar - 1]; tempVar += 2; break;
					case 5: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 7: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 9: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 11: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 13: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 15: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 17: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 19: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 21: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 23: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 25: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 27: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 29: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 31: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 33: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 35: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 37: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 39: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 41: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 43: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 45: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 47: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 49: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 51: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 53: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 55: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 57: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 59: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 61: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 63: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 65: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 67: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 69: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
					case 71: parity ^= bitStream[tempVar - 1]; tempVar += 2; break;
				}
			}
			
			//If an error is detected
			if (bitStream[0] != parity) {
				errors[i-1] = 1;
			}
		}
		//Second check bit
		else if (i == 2) {
			tempVar = 3; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 3: parity = bitStream[tempVar - 1]; tempVar += 3; break;
					case 6: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 7: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 10: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 11: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 14: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 15: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 18: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 19: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 22: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 23: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 26: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 27: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 30: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 31: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 34: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 35: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 38: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 39: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 42: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 43: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 46: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 47: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 50: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 51: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 54: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 55: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 58: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 59: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 62: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 63: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 66: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 67: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
					case 70: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 71: parity ^= bitStream[tempVar - 1]; tempVar += 3; break;
				}
			}
			
			//If an error is detected
			if (bitStream[1] != parity) {
				errors[i-1] = 1;
			}
		}
		//Third check bit
		else if (i == 3) {
			tempVar = 5; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 5: parity = bitStream[tempVar - 1]; tempVar++; break;
					case 6: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 7: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 12: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 13: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 14: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 15: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 20: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 21: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 22: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 23: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 28: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 29: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 30: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 31: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 36: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 37: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 38: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 39: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 44: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 45: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 46: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 47: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 52: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 53: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 54: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 55: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 60: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 61: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 62: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 63: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
					case 68: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 69: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 70: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 71: parity ^= bitStream[tempVar - 1]; tempVar += 5; break;
				}
			}
			
			//If an error is detected
			if (bitStream[3] != parity) {
				errors[i-1] = 1;
			}
		}
		//Fourth check bit
		else if (i == 4) {
			tempVar = 9; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 9: parity = bitStream[tempVar - 1]; tempVar++; break;
					case 10: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 11: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 12: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 13: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 14: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 15: parity ^= bitStream[tempVar - 1]; tempVar += 9; break;
					case 24: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 25: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 26: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 27: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 28: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 29: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 30: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 31: parity ^= bitStream[tempVar - 1]; tempVar += 9; break;
					case 40: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 41: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 42: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 43: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 44: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 45: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 46: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 47: parity ^= bitStream[tempVar - 1]; tempVar += 9; break;
					case 56: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 57: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 58: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 59: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 60: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 61: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 62: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 63: parity ^= bitStream[tempVar - 1]; tempVar += 9; break;
				}
			}
			
			//If an error is detected
			if (bitStream[7] != parity) {
				errors[i-1] = 1;
			}
		}
		//Fifth check bit
		else if (i == 5) {
			tempVar = 17; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 17: parity = bitStream[tempVar - 1]; tempVar++; break;
					case 18: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 19: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 20: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 21: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 22: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 23: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 24: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 25: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 26: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 27: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 28: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 29: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 30: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 31: parity ^= bitStream[tempVar - 1]; tempVar += 17; break;
					case 48: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 49: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 50: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 51: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 52: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 53: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 54: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 55: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 56: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 57: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 58: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 59: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 60: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 61: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 62: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 63: parity ^= bitStream[tempVar - 1]; tempVar += 17; break;
				}
			}
			
			//If an error is detected
			if (bitStream[15] != parity) {
				errors[i-1] = 1;
			}
		}
		//Sixth check bit
		else if (i == 6) {
			tempVar = 33; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 33: parity = bitStream[tempVar - 1]; tempVar++; break;
					case 34: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 35: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 36: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 37: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 38: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 39: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 40: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 41: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 42: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 43: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 44: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 45: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 46: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 47: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 48: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 49: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 50: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 51: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 52: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 53: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 54: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 55: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 56: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 57: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 58: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 59: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 60: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 61: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 62: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 63: parity ^= bitStream[tempVar - 1]; tempVar += 10; break;
				}
			}
			
			//If an error is detected
			if (bitStream[31] != parity) {
				errors[i-1] = 1;
			}
		}
		//Seventh check bit
		else {
			tempVar = 65; //Used to track index
			
			//Loop runs a switch statement to perform exclusive or calculations
			while (tempVar <= numBits) {
				switch (tempVar) {
					case 65: parity = bitStream[tempVar - 1]; tempVar++; break;
					case 66: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 67: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 68: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 69: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 70: parity ^= bitStream[tempVar - 1]; tempVar++; break;
					case 71: parity ^= bitStream[tempVar - 1]; tempVar++; break;
				}
			}
			
			//If an error is detected
			if (bitStream[63] != parity) {
				errors[i-1] = 1;
			}
		}
	}
	
	//Loop checks if error array was updated when check bits were analyzed
	for (int i = 0; i < 7; i++) {
		if (errors[i] == 1) {
			errorCorrector(bitStream, errors); //Call different function to correct errors
			break;
		}
	}
} //checkParityBits

//Function corrects errors by looking at which parity bits were affected by the error
void errorCorrector(int bitStream[], int errors[]) {
	
	//If statements go through various combinations of parity bits to determine where error is located
	//After error is found, bit ^ 1 is done to flip the error bit
	if (errors[6] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[70] ^= 1;
	}
	else if (errors[6] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[69] ^= 1;
	}
	else if (errors[6] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[68] ^= 1;
	}
	else if (errors[6] == 1 && errors[2] == 1) {
		bitStream[67] ^= 1;
	}
	else if (errors[6] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[66] ^= 1;
	}
	else if (errors[6] == 1 && errors[1] == 1) {
		bitStream[65] ^= 1;
	}
	else if (errors[6] == 1 && errors[0] == 1) {
		bitStream[64] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[62] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[61] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[60] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[2] == 1) {
		bitStream[59] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[58] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[1] == 1) {
		bitStream[57] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1 && errors[0] == 1) {
		bitStream[56] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[3] == 1) {
		bitStream[55] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[54] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[53] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[52] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[2] == 1) {
		bitStream[51] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[50] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[1] == 1) {
		bitStream[49] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1 && errors[0] == 1) {
		bitStream[48] ^= 1;
	}
	else if (errors[5] == 1 && errors[4] == 1) {
		bitStream[47] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[46] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[45] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[44] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[2] == 1) {
		bitStream[43] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[42] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[1] == 1) {
		bitStream[41] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1 && errors[0] == 1) {
		bitStream[40] ^= 1;
	}
	else if (errors[5] == 1 && errors[3] == 1) {
		bitStream[39] ^= 1;
	}
	else if (errors[5] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[38] ^= 1;
	}
	else if (errors[5] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[37] ^= 1;
	}
	else if (errors[5] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[36] ^= 1;
	}
	else if (errors[5] == 1 && errors[2] == 1) {
		bitStream[35] ^= 1;
	}
	else if (errors[5] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[34] ^= 1;
	}
	else if (errors[5] == 1 && errors[1] == 1) {
		bitStream[33] ^= 1;
	}
	else if (errors[5] == 1 && errors[0] == 1) {
		bitStream[32] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[30] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[29] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[28] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[2] == 1) {
		bitStream[27] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[26] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[1] == 1) {
		bitStream[25] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1 && errors[0] == 1) {
		bitStream[24] ^= 1;
	}
	else if (errors[4] == 1 && errors[3] == 1) {
		bitStream[23] ^= 1;
	}
	else if (errors[4] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[22] ^= 1;
	}
	else if (errors[4] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[21] ^= 1;
	}
	else if (errors[4] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[20] ^= 1;
	}
	else if (errors[4] == 1 && errors[2] == 1) {
		bitStream[19] ^= 1;
	}
	else if (errors[4] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[18] ^= 1;
	}
	else if (errors[4] == 1 && errors[1] == 1) {
		bitStream[17] ^= 1;
	}
	else if (errors[4] == 1 && errors[0] == 1) {
		bitStream[16] ^= 1;
	}
	else if (errors[3] == 1 && errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[14] ^= 1;
	}
	else if (errors[3] == 1 && errors[2] == 1 && errors[1] == 1) {
		bitStream[13] ^= 1;
	}
	else if (errors[3] == 1 && errors[2] == 1 && errors[0] == 1) {
		bitStream[12] ^= 1;
	}
	else if (errors[3] == 1 && errors[2] == 1) {
		bitStream[11] ^= 1;
	}
	else if (errors[3] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[10] ^= 1;
	}
	else if (errors[3] == 1 && errors[1] == 1) {
		bitStream[9] ^= 1;
	}
	else if (errors[3] == 1 && errors[0] == 1) {
		bitStream[8] ^= 1;
	}
	else if (errors[2] == 1 && errors[1] == 1 && errors[0] == 1) {
		bitStream[6] ^= 1;
	}
	else if (errors[2] == 1 && errors[1] == 1) {
		bitStream[5] ^= 1;
	}
	else if (errors[2] == 1 && errors[0] == 1) {
		bitStream[4] ^= 1;
	}
	else if (errors[1] == 1 && errors[0] == 1) {
		bitStream[2] ^= 1;
	}
	//Unlikely this code will ever execute
	else {
		printf("\nCould not find error!\n");
	}
} //errorCorrector
