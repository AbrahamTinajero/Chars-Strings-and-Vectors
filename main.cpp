/*
Assignment Name: Week 8 Lab 1
Project Name: char, strings, vector Arrays
Executable Name:diff_array 
Programmer's Name: Abraham Tinajero S02281565
Instructor's Name: Dr. Ed Polak
Date Created: October 9, 2018
Date Assigned; October 9, 2018
Date Last Modified; October 28, 2018

Date Due: November 2, 2018

Problem Statement:
Write an algorithm create three (3) different arrays One of char type, string type and vector type. The size of the each array is 7 items. Use a separate function to collect each array input. Write the output to the screen and to a file named “Week8ArrayTypesOutput.txt” The output format for the screen and file is shown below:

Unsorted char Unsorted Strings Unsorted Vectors
Colorado Mustang horse Soccer
New Mexico Apple core Football
Alaska Ranch dressing Baseball
Arkansas Pineapple pizza Racket ball
South Dakota Carmel candy Basketball
Oregon Hot dogs Golf
California Wild Surf Tennis

The values above must be part of the input and output of the program. The other values of the array will be provided by the individual programmer.

#define ROW 7
#define COL 20

//declaration of functions return nothing and pass-by-reference
void getChars(char arrayOfChars[ROW][COL]);//pass-by-reference (memory address)
void getStrings(string arrayOfStrings[]);//pass-by-reference (memory address)
void getVectors(vector<string> &vectorOfStrings);//pass-by-reference (memoryaddr)

Hint: The best loop when number of iteration is known is a flow control for loop.
*/

// basic file operations
#include <cstdlib>
#include <iostream> //needed for cout, cin, endl
#include <iomanip> //needed for setw and setprecision
#include <fstream> //needed for file IO
#include <string>//needed for string variables
#include <cstring>//needed for char array functions
#include <vector>//need for vector arrays
using namespace std;//save typing
//Global Variables
#define ROW 7//define number of rows
#define COL 20//define length of char words

//formal function prototypes declaration
void getChars(char arrayOfChars[ROW][COL]);//pass-by-reference (memory address)
void getStrings(string arrayOfStrings[]);//pass-by-reference (memory address)
void getVectors(vector<string> &vectorOfStrings);//pass-by-reference (memoryaddr)

//begin main function 
int main () {
char arrayOfChar[ROW][COL];//declare array of chars rows by columns matrics
string arrayStrg[ROW];//declare array of strings
vector<string> arrayOfVect;//declare array of vectors of string type

ofstream myfile;// declare variable of output file stream type

myfile.open ("Week8ArrayOutput.txt"); //open the the file

//check if file is open
if(!myfile.is_open()){
cout << "Error Opening file!\n";
//system("pause");
exit(1);//exit program with fail error status
}
//call functions
getChars(arrayOfChar);//call the char function
getStrings(arrayStrg);//call the string function
getVectors(arrayOfVect);//call the vector function

//display header of array output to the screen
cout << setw(18) << left << setw(18) << "Unsorted Chars\t"
<< left << setw(18) << " Unsorted Strings\t"
<< left << setw(18) << " Unsorted Vectors\n";

//write the content of the arrays to the monitor
for(int index = 0; index < ROW; index++){
cout << left << setw(17) << arrayOfChar[index] << "    "
<< setw(17) << left << arrayStrg[index] << "\t "
<< setw(17) << left << arrayOfVect[index] << "\n";
}//end of for loop

//write header of array output to the file
myfile << setw(18) << left << setw(18) << "Unsorted Chars\t"
<< left << setw(18) << " Unsorted Strings\t"
<< left << setw(18) << " Unsorted Vectors\n";

//write the content of the arrays to the monitor
for(int index = 0; index < ROW; index++){//for loop
myfile << left << setw(17) << arrayOfChar[index] << "    "
<< setw(17) << left << arrayStrg[index] << "\t "
<< setw(17) << left << arrayOfVect[index] << "\n";
}//end of for loop

//close the output file
myfile.close();
//system("pause");//pause output
return 0;
}// end of main function

//Begin getStrings function definition argument pass-by-reference
void getStrings(string arrayOfStrings[]){
int count = 0;//declare and initialize count variable
for(int idx = 0; idx < ROW; ++idx){//for loop
cout << idx + 1 <<". Enter a string value: ";//Prompt user to enter string value
getline(cin, arrayOfStrings[idx]);//Store keyboard input into arrayOfStrings variable
}//end of for loop
return;// return to main function
}//end of getStrings

//Begin getChars function definition argument pass-by-reference
void getChars(char arrayOfChars[ROW][COL]){
int count = 0;//declare and initialize count variable
for(int idx = 0; idx < ROW; ++idx){//for loop
cout << idx + 1 <<". Enter a char string value: ";//prompt for char string input
cin.getline(arrayOfChars[idx], COL);//store keyboard input up-to-length of global column value
}//end of for loop
return;// return to main function
}

//Begin getVectors function definition argument pass-by-reference
void getVectors(vector<string> &vectorOfStrings){
string input;//declare variable of string type

for(int idx = 0; idx < ROW; ++idx){//for loop
cout << idx + 1 <<". Enter a vector string value: ";//prompt for vector string input
getline(cin, input);//Store keyboard input into input string variable
vectorOfStrings.push_back(input);//Store input string variable into the vector array
}//end of for loop
return;// return to main function
}

