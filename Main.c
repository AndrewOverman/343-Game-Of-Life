/*
 * Created By: Andrew Overman & Tim Van Dyke
 * Date: 2/7/2017
 * Main file for Project 1 
 *
 */

	#include "file_utilities.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	
/*
 *This is a main method to run the whole project
 *@Param int argc: The number of arguments given in the command line
 *@Param char** argv: The array of arguments given in the command line
 */

int main(int argc, char** argv){
	
	/** ints for the for loops later */
	int i, j = 0;

	//https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm we used this to learn how to use atoi
	/** x and y are the columns and rows for our board */
	int x = atoi(argv[2]);
	int y = atoi(argv[1]);
	
	/** this double pointer points to a list of pointers. We itterate through this list of pointers whenever we want to change or read the board. */ 
	int** board;

	/** this double pointer is a copy of board and is reffered to when board is currently being changed so that the changes can remain consistent. */
	int** copy;

	//these method calls instantiate board and copy to the size specified in the command line
	createBoard(x, y, (&board));
	createBoard(x, y, (&copy));
	
	/** This is the filename used later in the save and load functions */
	char* filename = "test.txt";

	/** This is the int that the user changes to make their choice of action */
	int choose = 1;
	
	//an int to make a while true loop
	int q = 100;

	//a string to take the userinput for the option they choose
	char* uInput = malloc(sizeof(char));

	//a while true loop that continues until the user gives invalid input, or the exit input
	while(q == 100){
		
		//the 4 input options
		printf("Options: \n");
		printf("\tto Load: press 1\n");
		printf("\tto Save: press 2\n");
		printf("\tto Cont: press 3\n");
		printf("\tto Exit: press 4\n");

		printf("\n");
		
		//I saw what you posted on slack about scanf, but I didn't see any alternatives and this doesn't seem to be causing errors for me so I used it. 
		//https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output I used this for reference on how to use it
		scanf("%s", uInput);
		
		choose = atoi(uInput);

		printf("\n");
		
		//this is if the user picks to open a file. The file comes from the variable filename. Change this variable to choose a different file
		if(choose == 1){
			printf("loading...\n\n");
			char* container;
			int check;
			check = read_file(filename, &container);
			if (check == 1) {
				printf("Sorry, I could not find the file");
			}
			char end = '\n';
			int count = 0;
			for (i = 0; i < x; i++) {
				for (j = 0; j < y; j++) {
					if (container[count] == end) {
						count++;
					}
					board[i][j] = (container[count] - 48);
					count++;
				}
			}
			printf("Here is your board:\n\n");
			updateBoard(x, y, (&board));
			free(container);
		}
		//this is to save the board to a file. The file comes from the variable filename. Change this variable to choose a different save location. 
		else if(choose == 2){
			printf("saving...\n\n");
			char* container;
			int size = ((sizeof(int)*x)*y) + sizeof(char) * x;
			container = malloc(size);
			int count = 0;
			for (i = 0; i < x; i++) {
				for (j = 0; j < y; j++) {
					container[count] = (board[i][j] + 48);
					count++;
				}
				container[count] = '\n';
				count++;
			}
			write_file("test2.txt", container, size);
			free(container);
		}
		//This is the next generation option. All the code for making the next generation and printing it will run if this is chosen. 
		else if(choose == 3){
			printf("The Next Generation is: \n\n");
			copyBoard(x, y, (&board), (&copy));
			//this calls check Surround on every spot on the board
			for(i = 0; i < x; i++){
				for(j = 0; j < y; j++){	
					board[i][j] = checkSurround(i, j, (&copy));
				}
			}
			updateBoard(x, y, (&board));
		}
		//this is what happens when the user gives invalid input or the exit code. It frees all the memory in the board and copy, then frees board and copy.
		//https://www.tutorialspoint.com/c_standard_library/c_function_free.htm I used this for reference
		else {
			printf("goodbye\n");
			for (i = 0; i < x; i++) {
				free(board[i]);
				free(copy[i]);
			}
			free(board);
			free(copy);
			return 0;
		}
	}
}
