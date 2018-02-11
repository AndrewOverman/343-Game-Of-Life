/*
 *Header file for Game of Life simulator
 *Created By: Andrew Overman & Tim Van Dyke
 *Date: January 29, 2018
 */

/*
 *Reads in the contents of a file to the program
 *@Param char* filename: The name of the file bing read
 *@Param char** buffer: This is a pointer to the head of ...?FIXME
 *@return int: 0 if successful
 */
int read_file( char* filename, char** buffer );

/*
 *Saves the contents of the simulator to a file.
 *@Param char* filename: This is the name of the file that it saves to
 *@Param char* buffer: FIXME
 *@Param int size: This is the number of elements FIXME
 *@return int: 0 if successful
 */
int write_file( char* filename, char* buffer, int size);

/*
 *A method to request memory for the board
 *@Param int x: the height of the board
 *@Param int y: the width of the board
 *@return int: 0 if successful
 */
int createBoard(int x, int y);

/*
 *A method to check the surroundings of a cell and update that cell
 *@Param int x: the x coordinate of the cell
 *@Param int y: the y coordinate of the cell
 *@return int: what the cell was changed to
 */
int checkSurroundings(int x, int y);
