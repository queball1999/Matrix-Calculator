/*	ENG175IN	Summer 2020
 *
 *	Author:	Quynn Bell
 *
 *	Date Created:	10th of June 2020
 *
 *	Copyright @Qbell.	All Rights Reserved.
 *
 *	Program Function: Matrix Calculator. This program will ONLY work with integers and will handle matricies with max size 10x10.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>			// including standard input & output library
#include <stdlib.h>			// including standard library
#include <math.h>			// including math library
#include <time.h>			// including time library

// character for restarting program
char userRestart;

// user-defined functions declaration
void delay(int milli_seconds);
void ThreeDots();
int determinant(int matrix[10][10], int n);
int CalculatingN_MatrixA(int rowA, int colA, int* n);
int CalculatingN_MatrixB(int rowB, int colB, int* n);

int main(void) {


	// variables
	int matrixA[10][10];
	int matrixB[10][10];
	int i, j, n, k;
	int rowA, colA;
	int rowB, colB;
	int userInput;
	char userMenuInput;
	int matrixANSWER[10][10];
	int matrixANSWER2[10][10];
	int userMatriciesInput, userScalarInput, userScalarValue1, userScalarValue2, userMatrixChoice;


	// printing program name
	printf("Program: Matrix Calculator\n\n");


	// loop for entire program
	do {

		// user interface
		printf("This program will ONLY work with integers and will handle matricies with max size 10x10.\n\n");
		printf("Please enter your first matrix:\n");
		printf("Enter the number of Rows: ");
		scanf("%d", &rowA);
		while (rowA <= 0 || rowA > 10) { printf("Invalid Entry. Please enter a value (1 - 10): "); scanf("%d", &rowA); }
		printf("Enter the number of Columns: ");
		scanf("%d", &colA);
		while (colA <= 0 || colA > 10) { printf("Invalid Entry. Please enter a value (1 - 10): "); scanf("%d", &colA); }
		printf("You entered %dx%d\n\n", rowA, colA);

		printf("Please enter your second matrix:\n");
		printf("Enter the number of Rows: ");
		scanf("%d", &rowB);
		while (rowB <= 0 || rowB > 10) { printf("Invalid Entry. Please enter a value (1 - 10): "); scanf("%d", &rowA); }
		printf("Enter the number of Columns: ");
		scanf("%d", &colB);
		while (colB <= 0 || colB > 10) { printf("Invalid Entry. Please enter a value (1 - 10): "); scanf("%d", &colB); }
		printf("You entered %dx%d\n\n", rowB, colB);


		// user interface; defining matricies
		for (i = 0; i < rowA; i++) {
			for (j = 0; j < colA; j++) {
				printf("Matrix A[%d][%d]: ", i + 1, j + 1);
				scanf("%d", &matrixA[i][j]);
			}
		}
		printf("------------------\n");
		for (i = 0; i < rowB; i++) {
			for (j = 0; j < colB; j++) {
				printf("Matrix B[%d][%d]: ", i + 1, j + 1);
				scanf("%d", &matrixB[i][j]);
			}
		}


		printf("\nMatrix A:\n");


		for (i = 0; i < rowA; i++) {
			for (j = 0; j < colA; j++) {
				printf("%5d", matrixA[i][j]);
			}
			printf("\n");
		}


		printf("\nMatrix B:\n");


		for (i = 0; i < rowB; i++) {
			for (j = 0; j < colB; j++) {
				printf("%5d", matrixB[i][j]);
			}
			printf("\n");
		}

		// loop for user menu
		do {


			// user menu
			printf("\n\nHow would you like to work with these matricies?\n\n");
			printf("1 - Add     2 - Subtract     3 - Scalar Multiply     4 - Matrix Multiply     5 - Transpose     6 - Determinant\n\n");
			printf("Please enter a choice: ");
			scanf("%d", &userInput);


			// validation for user input
			while ((userInput <= 0) || (userInput >= 7)) { printf("Invalid Entry. Please enter a value (1 - 6): "); scanf("%d", &userInput); }

			// switch...case for user input
			switch (userInput) {

			case 1:
				// Addition
				printf("You chose to Add!\n\n");
				delay(500);
				printf("Learning how to add numbers");
				ThreeDots();

;				if ((rowA != rowB) || (colA != colB)) { printf("Invalid Entry. Matricies are not the same size!\n"); break; }

				if ((rowA == rowB) && (colA == colB)) {
					for (i = 0; i < rowB; i++) {
						for (j = 0; j < colB; j++) {
							matrixANSWER[i][j] = matrixA[i][j] + matrixB[i][j];
						}
					}
				}

				printf("The two matricies added are:\n");

				for (i = 0; i < rowB; i++) {
					for (j = 0; j < colB; j++) {
						printf("%5d", matrixANSWER[i][j]);
					}
					printf("\n");
				}

				break;

			case 2:
				// subtraction
				printf("You chose to Subtract!\n\n");
				delay(500);
				printf("Slashing those numbers");
				ThreeDots();

				if ((rowA != rowB) || (colA != colB)) { printf("Invalid Entry. Matricies are not the same size!\n"); break; }

				if ((rowA == rowB) && (colA == colB)) {
					for (i = 0; i < rowB; i++) {
						for (j = 0; j < colB; j++) {
							matrixANSWER[i][j] = matrixA[i][j] - matrixB[i][j];
						}
					}
				}

				printf("The two matricies subtracted are:\n");

				for (i = 0; i < rowB; i++) {
					for (j = 0; j < colB; j++) {
						printf("%5d", matrixANSWER[i][j]);
					}
					printf("\n");
				}

				break;

			case 3:
				// Scalar multiply
				printf("You chose to Scalar Multiply!\n\n");
				printf("How many matricies do you want to use? (1 / 2): ");
				scanf("%d", &userMatriciesInput);

				while ((userMatriciesInput <= 0) || (userMatriciesInput >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userMatriciesInput); }

				switch (userMatriciesInput) {

				case 1:

					printf("Which matrix would you like to use? (1 / 2): ");
					scanf("%d", &userMatrixChoice);
					while ((userMatrixChoice <= 0) || (userMatrixChoice >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userMatrixChoice); }
					printf("Please enter the scalar value: ");
					scanf("%d", &userScalarValue1);
					switch (userMatrixChoice) {

					case 1:

						delay(500);
						printf("\nPhoning a friend to ask how to multiply");
						ThreeDots();

						printf("The scalar value of matrixA and %d is:\n", userScalarValue1);
						for (i = 0; i < rowA; i++) {
							for (j = 0; j < colA; j++) {
								matrixANSWER[i][j] = userScalarValue1 * matrixA[i][j];
								printf("%5d", matrixANSWER[i][j]);
							}
							printf("\n");
						}
						break;

					case 2:

						delay(500);
						printf("\nAsking tutor for help on multiplying");
						ThreeDots();

						printf("The scalar value of matrixB and %d is:\n", userScalarValue1);
						for (i = 0; i < rowB; i++) {
							for (j = 0; j < colB; j++) {
								matrixANSWER2[i][j] = userScalarValue1 * matrixB[i][j];
								printf("%5d", matrixANSWER2[i][j]);
							}
							printf("\n");
						}
						break;
					}
					break;

				case 2:

					printf("How many scalar values do you want to use? (1 / 2): ");
					scanf("%d", &userScalarInput);
					while ((userScalarInput <= 0) || (userScalarInput >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userScalarInput); }

					switch (userScalarInput) {

					case 1:

						printf("Please enter one scalar value: ");
						scanf("%d", &userScalarValue1);
						delay(500);
						printf("\nAsking my parents how to multiply");
						ThreeDots();

						printf("The scalar value of matrixA and %d is:\n", userScalarValue1);
						for (i = 0; i < rowA; i++) {
							for (j = 0; j < colA; j++) {
								matrixANSWER[i][j] = userScalarValue1 * matrixA[i][j];
								printf("%5d", matrixANSWER[i][j]);
							}
							printf("\n");
						}
						printf("The scalar value of matrixB and %d is:\n", userScalarValue1);
						for (i = 0; i < rowB; i++) {
							for (j = 0; j < colB; j++) {
								matrixANSWER2[i][j] = userScalarValue1 * matrixB[i][j];
								printf("%5d", matrixANSWER2[i][j]);
							}
							printf("\n");
						}
						break;

					case 2:

						printf("Please enter the scalar value for the first matrix: ");
						scanf("%d", &userScalarValue1);
						printf("Please enter the scalar value for the second matrix: ");
						scanf("%d", &userScalarValue2);
						delay(500);
						printf("\nAsking stranger on the web how to multiply");
						ThreeDots();

						printf("The scalar value of matrixA and %d is:\n", userScalarValue1);
						for (i = 0; i < rowA; i++) {
							for (j = 0; j < colA; j++) {
								matrixANSWER[i][j] = userScalarValue1 * matrixA[i][j];
								printf("%5d", matrixANSWER[i][j]);
							}
							printf("\n");
						}
						printf("The scalar value of matrixB and %d is:\n", userScalarValue2);
						for (i = 0; i < rowB; i++) {
							for (j = 0; j < colB; j++) {
								matrixANSWER2[i][j] = userScalarValue2 * matrixB[i][j];
								printf("%5d", matrixANSWER2[i][j]);
							}
							printf("\n");
						}
						break;
					}
				}
				break;

			case 4:
				// Matrix multiply
				printf("You chose to Matrix Muiltiply!\n\n");
				delay(500);
				printf("Learning about math");
				ThreeDots();

				printf("The multiplied matricies are:\n");

				if ((colA == rowB)) {
					for (i = 0; i < rowB; i++) {
						for (j = 0; j < colB; j++) {
							matrixANSWER[i][j] = 0;
							for (int k = 0; k < colA; k++) {
								matrixANSWER[i][j] += matrixA[i][k] * matrixB[k][j];
							}
						}
					}

					for (i = 0; i < rowA; i++) {
						for (j = 0; j < colB; j++) {
							printf("%d\t", matrixANSWER[i][j]);
						}
						printf("\n");
					}
				}
				else if (colA != rowB) {
					printf("\nUndefined! Matricies cannot be multiplied.\n\n");
				}

				break;

			case 5:
				// Transpose
				printf("You chose to Transpose!\n\n");

				printf("How many matricies do you want to use? (1 / 2): ");
				scanf("%d", &userMatriciesInput);

				while ((userMatriciesInput <= 0) || (userMatriciesInput >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userMatriciesInput); }

				switch (userMatriciesInput) {

				case 1:

					printf("Which matrix would you like to use? (1 / 2): ");
					scanf("%d", &userMatrixChoice);
					while ((userMatrixChoice <= 0) || (userMatrixChoice >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userMatrixChoice); }

					switch (userMatrixChoice) {

					case 1:

						delay(500);
						printf("\nAsking Cortana how to transpose numbers");
						ThreeDots();

						printf("The transposed matrixA is:\n");
						for (i = 0; i < colA; i++) {
							for (j = 0; j < rowA; j++) {
								matrixANSWER[i][j] = matrixA[j][i];
								printf("%5d", matrixANSWER[i][j]);
							}
							printf("\n");
						}
						break;

					case 2:

						delay(500);
						printf("\nAsking Siri how to transpose numbers");
						ThreeDots();

						printf("The transposed matrixB is:\n");
						for (i = 0; i < colB; i++) {
							for (j = 0; j < rowB; j++) {
								matrixANSWER2[i][j] = matrixB[j][i];
								printf("%5d", matrixANSWER2[i][j]);
							}
							printf("\n");
						}
						break;
					}
					break;

				case 2:

					delay(500);
					printf("\nAsking Alexa how to transpose numbers");
					ThreeDots();

					printf("The transposed matrixA is:\n");
					for (i = 0; i < colA; i++) {
						for (j = 0; j < rowA; j++) {
							matrixANSWER[i][j] = matrixA[j][i];
							printf("%5d", matrixANSWER[i][j]);
						}
						printf("\n");
					}
					printf("The transposed matrixB is:\n");
					for (i = 0; i < colB; i++) {
						for (j = 0; j < rowB; j++) {
							matrixANSWER2[i][j] = matrixB[j][i];
							printf("%5d", matrixANSWER2[i][j]);
						}
						printf("\n");
					}
					break;
				}
				break;

			case 6:
				// Determinant
				printf("You chose to Determinant!\n\n");
				printf("How many matricies do you want to use? (1 / 2): ");
				scanf("%d", &userMatriciesInput);

				while ((userMatriciesInput <= 0) || (userMatriciesInput >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userMatriciesInput); }

				switch (userMatriciesInput) {

				case 1:

					printf("Which matrix would you like to use? (1 / 2): ");
					scanf("%d", &userMatrixChoice);
					while ((userMatrixChoice <= 0) || (userMatrixChoice >= 3)) { printf("Invalid Entry. Please enter a value (1 - 2): "); scanf("%d", &userMatrixChoice); }

					switch (userMatrixChoice) {

					case 1:

						n = 0;
						if ((rowA != colA)) { printf("Invalid Entry. MatrixA is not square!\n"); break; }
						if ((rowA > 10) && (colA > 10)) { n = 0; printf("Matricies exceed max size of this calculator!\n"); break; }
						CalculatingN_MatrixA(rowA, colA, &n);

						delay(500);
						printf("\nSearching yahoo answers for how to find determinant");
						ThreeDots();

						printf("The determinant of matrixA is: %d\n\n", determinant(matrixA, n));
						break;

					case 2:

						n = 0;
						if ((rowB != colB)) { printf("Invalid Entry. MatrixB is not square!\n"); break; }
						if ((rowB > 10) && (colB > 10)) { n = 0; printf("Matricies exceed max size of this calculator!\n"); break; }
						CalculatingN_MatrixB(rowB, colB, &n);

						delay(500);
						printf("\nGoogling how to find the determinant");
						ThreeDots();

						printf("The determinant of matrixB is: %d\n\n", determinant(matrixB, n));
						break;
					}
					break;

				case 2:

					n = 0;
					if ((rowA != colA)) { printf("Invalid Entry. MatrixA is not square!\n"); printf("Invalid Entry. MatrixB is not square!\n"); break; }
					if ((rowA > 10) && (colA > 10)) { n = 0; printf("Matricies exceed max size of this calculator!\n"); break; }
					CalculatingN_MatrixA(rowA, colA, &n);

					delay(500);
					printf("\nSearching bing for how to find the determinant");
					ThreeDots();

					printf("The determinant of matrixA is: %d\n", determinant(matrixA, n));
					n = 0;
					if ((rowB > 10) && (colB > 10)) { n = 0; printf("Matricies exceed max size of this calculator!\n"); break; }
					CalculatingN_MatrixB(rowB, colB, &n);

					printf("The determinant of matrixB is: %d\n\n", determinant(matrixB, n));
					break;

				}
				break;

			default:
				printf("Invalid Entry.");
				break;
			}

			// re-setting answers for multiple operations
			int matrixANSWER[10][10] = {
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			};

			int matrixANSWER2[10][10] = {
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			};

			// asking user if they want to add any other operations
			userMenuInput = 'q';					//forcing code to sit here, it was skipping for some reason. maybe overflow from before?
			printf("Would you like to add any other operations? (Y / N) ");
			scanf(" %c", &userMenuInput);


			// checking and validating user's response is either Y or N
			while ((userMenuInput != 'N') && (userMenuInput != 'n') && (userMenuInput != 'Y') && (userMenuInput != 'y')) { printf("Invalid Entry. Please enter Yes or No (Y / N) "); scanf(" %c", &userMenuInput); }


			// if user wants to exit, break from loop an exit. else continue the loop.
			if ((userMenuInput == 'N') || (userMenuInput == 'n')) { break; }
			if ((userMenuInput == 'Y') || (userMenuInput == 'y')) { continue; }

		} while ((userMenuInput == 'Y') || (userMenuInput == 'y'));



		// asking user if they want to restart program
		printf("Do you wish to restart the program? (Y / N) ");
		scanf(" %c", &userRestart);


		// checking and validating user's response is either Y or N
		while ((userRestart != 'N') && (userRestart != 'n') && (userRestart != 'Y') && (userRestart != 'y')) { printf("Invalid Entry. Please enter Yes or No (Y / N) "); scanf(" %c", &userRestart); }


		// if user wants to exit, break from loop an exit. else continue the loop.
		if ((userRestart == 'N') || (userRestart == 'n')) { printf("\nGoodbye.\n\n"); break; }
		else { printf("\n------------------------------------------------------------------------------------------------------------------------\n"); continue; }

	} while ((userRestart == 'Y') || (userRestart == 'y'));  // will restart loop if user entered Y.


	// printing endline
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");


	// exit program
	return 0;
}

// user defined function for delaying code. 
// modeled after delay() function in arduino languange.
void delay(int milli_seconds) {

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds);

}

// user defined function for inputting three dots with delay.
void ThreeDots() {
	delay(750);
	printf(".");
	delay(750);
	printf(".");
	delay(750);
	printf(".\n\n");
	delay(500);
}

// user defined function for calculating n
int CalculatingN_MatrixA(int rowA, int colA, int* n) {
	if ((rowA == 1) && (colA == 1)) { *n = 1; }
	if ((rowA == 2) && (colA == 2)) { *n = 2; }
	if ((rowA == 3) && (colA == 3)) { *n = 3; }
	if ((rowA == 4) && (colA == 4)) { *n = 4; }
	if ((rowA == 5) && (colA == 5)) { *n = 5; }
	if ((rowA == 6) && (colA == 6)) { *n = 6; }
	if ((rowA == 7) && (colA == 7)) { *n = 7; }
	if ((rowA == 8) && (colA == 8)) { *n = 8; }
	if ((rowA == 9) && (colA == 9)) { *n = 9; }
	if ((rowA == 10) && (colA == 10)) { *n = 10; }
}

// user defined function for calculating n
int CalculatingN_MatrixB(int rowB, int colB, int* n) {
if ((rowB == 1) && (colB == 1)) { *n = 1; }
if ((rowB == 2) && (colB == 2)) { *n = 2; }
if ((rowB == 3) && (colB == 3)) { *n = 3; }
if ((rowB == 4) && (colB == 4)) { *n = 4; }
if ((rowB == 5) && (colB == 5)) { *n = 5; }
if ((rowB == 6) && (colB == 6)) { *n = 6; }
if ((rowB == 7) && (colB == 7)) { *n = 7; }
if ((rowB == 8) && (colB == 8)) { *n = 8; }
if ((rowB == 9) && (colB == 9)) { *n = 9; }
if ((rowB == 10) && (colB == 10)) { *n = 10; }
}

// Determinant code below was written with help from Chandu Yadav on tutorialspoint.com
// I followed what he had in C++ to recreate this replica in C.
// This tutorial was extremely helpful as all others were insanely confusing.
// I was feeling confident until I tried over a 3x3 matrix, so I resorted to online resources.

int determinant(int matrix[10][10], int n) {
	int det = 0;
	int tempMatrix[10][10];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					tempMatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(tempMatrix, n - 1));
		}
	}
	return det;
}