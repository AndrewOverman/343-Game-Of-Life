/*
 *Header file for Game of Life simulator
 *Created By: Andrew Overman & Tim Van Dyke
 *Date: January 29, 2018
 */

/*
 *Reads in the contents of a file to the program
 *@Param char* filename: The name of the file bing read
 *@Param char** buffer: this is the actual board
 *@return int: 0 if successful
 */
int read_file( char* filename, char** buffer );

/*
 *Saves the contents of the simulator to a file.
 *@Param char* filename: This is the name of the file that it saves to
 *@Param char* buffer: This is the actual board
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
 *@return int: returns what the cell should be: 0 if empty, 1 if alive, 2 if dead
 */
int checkSurroundings(int x, int y, int** buffer);

/*
 *A method to render the board
 *@Param int** buffer: the board
 *@Param int x: the width of the board
 *@Param int y: the height of the board
 */
void renderBoard(int x, int y, int** buffer);
