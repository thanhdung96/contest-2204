#pragma once

// open specified file with max length for each line
int read(char* filePath, unsigned int lineMaxLength);

// move cursor to the next line and return the content of that line
char* nextLine();

// get content of current line without moving the cursor
char* getLine();

// close file and clear buffer
void closeFile();
