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

int main(int argc, char** argv){

	char* buffer = "hello there test";
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	createBoard(atoi(argv[1]),atoi(argv[2]));
	write_file("test.txt",buffer,0);
	read_file("test.txt",argv);



}
int createBoard(int x, int y){
	int i,j,count = 0;
	int *arr[x];
		
		for(i = 0; i < x; i++)
			 arr[i] = (int*)malloc(y * sizeof(int));

		for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){
				arr[i][j] = ++count;
				printf("%i", arr[i][j]);
			}
		}
		return 0;
}
int checkSurrondings(){
	return 0;
}
