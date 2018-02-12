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
	int i, j = 0;
	//char* buffer = "hello there test";
	//char userinput[80];
	int* board[atoi(argv[1])];

	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	
	*board = createBoard(atoi(argv[1]),atoi(argv[2]),*board);
	printf("%i\n", board);
/*
	while(){
		copyBoard(atoi(argv[1],atoi(argv[2]),board);
*/
	for(i = 0; i < atoi(argv[1]); i++){
		for(j = 0; j < atoi(argv[2]); j++){	
			checkSurround(atoi(argv[1]),atoi(argv[2]), board);
		}
	}

	//updateBoard(board, atoi(argv[1]),atoi(argv[2]));
	
		
	/*
		printf("Options: \n");
		printf("		-Continue\n");
		printf("		-Save\n");
		printf("		-Load\n");
		scanf("%s",userinput);

		if(userinput.tolower = "continue"){
				
		}
		else if(userinput.tolower = "save"){
			write_file(placeholder,placeholder,placerholder);
		}
		else{
			read_file(placeholder,placeholder,placeholder);
		}
	}
*/
}

