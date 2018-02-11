/*
 * Created By: Andrew Overman 
 * Date: 2/7/2018
 * C Code for the file utilities methods
 */

#include <stdio.h>
#include <stdlib.h>

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
			return 0;
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
}

/*
 *A method to request memory for the board
 *@Param int x: the height of the board
 *@Param int y: the width of the board
 *@return int: 0 if successful
 */
int createBoard(int x, int y){
	int i, j, count = 0'
	int *arr[x];

		for(i = 0; i < x; i++)
			arr[i] = (int*)malloc(y* sizeof(int));

		for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){
				arr[i][j] = ++count;
				printf("%i", arr[i][j]);
			}
		}
		return 0;
}

/*
 *A method to check the surroundings of the cell and update the cell
 *@Param int x: the x coordinate of the cell
 *@Param int y: the y coordinate of the cell
 */
int checkSurroundings(int x, int y){

}
