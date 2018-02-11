/*
 * Created By: Andrew Overman 
 * Date: 2/7/2018
 * C Code for the file utilities methods
 */

#include <stdio.h>
#include <stdlib.h>

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

int write_file( char* filename, char *buffer, int size){
		FILE *fileptr;

		fileptr = fopen(filename, "w");

		if(fileptr == NULL){
			printf("Error, could not find file\n");
			return 0;
		}

		fprintf(fileptr, buffer, size);
}
