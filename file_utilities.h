/*
 *Header file for Game of Life simulator
 *Created By: Andrew Overman & Tim VanDyke(?maybe right spelling)
 *Date: January 29, 2018
 *
 */

//Reads in the contents of a file to the program
int read_file( char* filename, char **buffer );

//Saves the contents of the simulator to a file.
int write_file( char* filename, char *buffer, int size);
