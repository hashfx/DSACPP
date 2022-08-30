#include<iostream>
#include<fstream> // used for writing in files
#FIXME: error in input through open()
/*
Classes inside <fstream>:
    fstream : Input/output file stream class (class )
    ifstream : Input file stream class (class )
    ofstream : Output file stream (class )
    filebuf : File stream buffer (class )
*/

using namespace std;
int main()
{

    string content = "This file is to be WRITE by C++ File Handling Program";
    /*
    2 ways to open a file:
        -> using constructor
        -> using open() function
    */

   // Writing File using constructor
   ofstream out("fwriting.txt"); // File open for writing in file_handling.txt
   out << content; // Shifting matter from 'string content' to 'ofstream out'
    // open()
//    out.open("freading.txt"); // to open the file and close it after reading automatically
   out << "This content is entered through open()\n";
   out << "And this is new line...";
   out.close();

   // Reading File using constructor
   ifstream in("freading.txt"); // File open for reading in file_handling.txt
//    in >> content; // Shifting matter from 'string content' to 'ofstream out' // displays string at [0] only
   getline(in ,content);
//    getline(in ,content); // to read 2nd line only

   cout << content; // Printing content of 'file_handling.txt'
    // open()
   
   in.open("fwriting.txt");
   in >> "Thorugh in fn";
   in >> "nu line";
   in.close();    // to close the file


    // Using open() function
    



   return 0;
}