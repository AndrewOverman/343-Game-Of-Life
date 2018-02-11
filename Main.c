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
/*
 *This is a main method to run the whole project
 *@Param int argc: The number of arguments given in the command line
 *@Param char** argv: The array of arguments given in the command line
 */
int main(int argc, char** argv){

	char* buffer = "hello there test";
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	createBoard(atoi(argv[1]),atoi(argv[2]));
	write_file("test.txt",buffer,0);
	read_file("test.txt",argv);



}

