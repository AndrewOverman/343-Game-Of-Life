/*
 * Created By: Andrew Overman 
 * Date: 2/7/2018
 * C Code for the file utilities methods
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 *Reads in the contents of a file to the program
 *@Param char* filename: The name of the file being read
 *@Param char** buffer: The array that the board is being saved into
 *@return int: 0 if successful
 */
int read_file( char* filename, char **buffer ){

		FILE *fileptr;

		fileptr = fopen(filename,"r");

		if(fileptr == NULL){
			printf("Error, could not find file\n");
			return 1;
		}
	
		while(fgets(*buffer,1000,fileptr)!=NULL){
			printf("%s",*buffer);
		}

		fclose(fileptr);

		return 0;
}

/*
 *Saves the contents of the simulator to a file.
 *@Param char* filename: This is the name of the file that the method saves to
 *@Param char* buffer: The array that the board is being saved into
 *@Param int size: The size of the file being saved
 *@return int: 0 if successful
 */
int write_file( char* filename, char *buffer, int size){
		FILE *fileptr;

		fileptr = fopen(filename, "w");

		if(fileptr == NULL){
			printf("Error, could not find file\n");
			return 0;
		}

		fprintf(fileptr, buffer, size);
		return 0;
}

/*
 *A method to request memory for the board
 *@Param int x: the height of the board
 *@Param int y: the width of the board
 *@return int: 0 if successful
 * I got help from Alan Sisouphone on Slack for how to pass the array around
 * We also used https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/ for reference. We used example number 3 on this site. 
 */
void createBoard(int x, int y, int*** buffer){
	int i, j = 0;
	(*buffer) = (int**)malloc(x * sizeof(int *));
	for (i = 0; i < x; i++)
		(*buffer)[i] = (int*)malloc(y * sizeof(int));
	
	for (i = 0; i < x; i++)
		for(j = 0; j < y; j++)
			(*buffer)[i][j] = 0;
}

/*
 *A method to check the surroundings of the cell and update the cell
 *@Param int x: the x coordinate of the cell
 *@Param int y: the y coordinate of the cell
 *@Param int** buffer: the board
 *@return int: returns what the cell should be: 0 if empty, 1 if alive, 2 if dead
 * I got help from Alan Sisouphone for how to pass the array around
 */
int checkSurround(int x, int y, int*** buffer){
	int state = (*buffer)[x][y];
	int count = 0;
	//This if block checks all non edge or corner spaces
	if(x > 0 && y > 0 && x < (sizeof((*buffer))/sizeof(int*)) && y < (sizeof((*buffer)[0])/sizeof(int))) {
		x--;
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		x = x - 2;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x = x + 2;
		if ((*buffer)[x][y] == 1)
			count++;
		x = x - 2;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
	} //This if block checks the top left corner
	else if(x == 0 && y == 0) {
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		x--;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
	} //This if block checks the bottom right corner
	else if(x == (sizeof((*buffer))/sizeof(int*)) && y == (sizeof((*buffer)[0])/sizeof(int))) {
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
		x--;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
	} //This if block checks the bottom left corner
	else if(x == 0 && y == (sizeof((*buffer)[0])/sizeof(int))) {
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
	} //This if block checks the top right corner
	else if(x == (sizeof((*buffer))/sizeof(int*)) && y == 0) {
		x--;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
	}// This if block checks the Left edge
	else if(x == 0 && y > 0 && y < (sizeof((*buffer)[0])/sizeof(int))) {
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x--;
		if ((*buffer)[x][y] == 1)
			count++;
	}//This if block checks the right Edge
	else if(x == (sizeof((*buffer))/sizeof(int*)) && y > 0 && y < (sizeof((*buffer)[0])/sizeof(int))) {
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
		x--;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
	}//This if block checks the top edge
	else if(y == 0 && x > 0 && x < (sizeof((*buffer))/sizeof(int*))) {
		x--;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
	}//This if block checks the bottom edge
	else if(y == (sizeof((*buffer))/sizeof(int*)) && x > 0 && x < (sizeof((*buffer)[0])/sizeof(int*))) {
		x--;
		if ((*buffer)[x][y] == 1)
			count++;
		y--;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		x++;
		if ((*buffer)[x][y] == 1)
			count++;
		y++;
		if ((*buffer)[x][y] == 1)
			count++;
	}//This checks count to see how many neighbors there are, and also checks state to see what the correct action to take is.
	if (count < 2 && state == 1)
		return 2;
	else if ((count == 2 || count == 3) && state  == 1)
		return 1;
	else if (count == 3 && state == 2)
		return 1;
	else if (count > 3 && state == 1)
		return 2;
	else
		return state;
	return 0;
}

/*
 *A method to make a copy of the board
 *@Param int** buffer: the board
 *@Param int x: the width of the board
 *@Param int y: the height of the board
 * I got help from Alan Sisouphone to know how to pass the array around
 */
void copyBoard(int x, int y, int*** buffer, int*** copy){
	int i, j = 0;

	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			(*copy)[i][j] = (*buffer)[i][j];
		}
	}
}

/*
 *A method to display the new board after a generation
 *@Param int* buffer: the board
 *@Param int x: the width of the board
 *@Param int y: the height of the board
 */
void updateBoard(int x, int y, int*** buffer){
	int i, j = 0;

	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			printf("|%i",(*buffer)[i][j]);		
		}
		printf("|\n");
	}
	printf("\n\n\n");
}
