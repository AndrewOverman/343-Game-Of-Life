/*
 * Created By: Andrew Overman 
 * Date: 2/7/2018
 * C Code for the file utilities methods
 */

#include <stdio.h>

int read_file( char* filename, char **buffer ){

		FILE *fileptr;

		fileptr = fopen(filename,"r");

		if(!fileptr){
			return 1;
		}
		
		while(fgets(*buffer,1000,fileptr)!=NULL){
			printf("%s",*buffer);
			/*
			if(x == 0){
				width = *fileptr;
			}
			if(x == 1){
				height = *fileptr;
			}
			*/
		}
		fclose(fileptr);

		return 0;
}

int write_file( char* filename, char *buffer, int size){



}
