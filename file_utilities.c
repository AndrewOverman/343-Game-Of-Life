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
 *@Param char** buffer: FIXME
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
 *@Param char* buffer: FIXME
 *@Param int size: This is the number of elements FIXME
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
 */
int** createBoard(int x, int y, int* Buffer){
	int i, j, count = 0;
	int *arr[x];
	Buffer = *arr;
		for(i = 0; i < x; i++)
			arr[i] = (int*)malloc(y* sizeof(int));

		for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){	
				arr[i][j] = 1;
				printf("|%i|",arr[i][j]);
			}
			printf("\n");
		}
		return Buffer;
}

/*
 *A method to check the surroundings of the cell and update the cell
 *@Param int x: the x coordinate of the cell
 *@Param int y: the y coordinate of the cell
 *@Param int** buffer: the board
 *@return int: returns what the cell should be: 0 if empty, 1 if alive, 2 if dead
 */
int checkSurroundings(int x, int y, int** buffer){
	int state = buffer[x][y];
	x--;
	y--;
	int count = 0;
	if (buffer[x][y] == 1)
		count++;
	x++;
	if (buffer[x][y] == 1)
		count++;
	x++;
	if (buffer[x][y] == 1)
		count++;
	x = x - 2;
	y++;
	if (buffer[x][y] == 1)
		count++;
	x = x + 2;
	if (buffer[x][y] == 1)
		count++;
	x = x - 2;
	y++;
	if (buffer[x][y] == 1)
		count++;
	x++;
	if (buffer[x][y] == 1)
		count++;
	x++;
	if (buffer[x][y] == 1)
		count++;
	if (count < 2 && state == 1)
		return 2;
	if ((count == 2 || count == 3) && state  == 1)
		return 1;
	if (count == 3 && state == 2)
		return 1;
	return 0;
}

/*
 *A method to make a copy of the board
 *@Param int** buffer: the board
 *@Param int x: the width of the board
 *@Param int y: the height of the board
 */
void copyBoard(int x, int y, int** buffer){
	int i, j = 0;
	int *copy[x];

	for(i = 0; i < x; i++)
		copy[i] = (int*)malloc(y* sizeof(int));

	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			copy[i][j] = buffer[i][j];
		}
	}
}

/*
 *A method to display the new board after a generation
 *@Param int** buffer: the board
 *@Param int x: the width of the board
 *@Param int y: the height of the board
 */
void updateBoard(int x, int y, int** buffer){
	int i, j = 0;

	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			printf("|%i|",buffer[i][j]);		
		}
		printf("\n");
	}
}
