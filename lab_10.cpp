//Program Name: Problem 9: Matrix Function and Operations Program
//Brief Description: This program will ask the user for a matrix text file and options choice for adding or multiplying matrices, finding the sum diagonal, swapping rows and columsn,a dn updating the matrix at row by cloumn locaiton wiht either integer or double precision values and using tempalte and polymorphism function.
//Input: The input will be a matrix text file contains a 2 nxn matrix, witht the first line indicating the size of the n x n matrix with a type value flag to indicate what type values are the matrix values in the matrix text file
//Ouput: The ouput will welcome the user and give a goodbye message to the user. Print result matrices based on what functions used and what type of matrix to deal with.
//All collaborators: None
//Other Sources:Github Copilot and ChatGPT 
//Author: Ryan Antony Pereira
//Creation Date: 4/12/2025
//Last Modified Date: 4/12/2025

//Includes the iostream library file to include standard input and ouput for cin and cout
#include <iostream>
//Includes the C++ fstream libary for file input and output, open and close functionality
#include <fstream>
//Includes the C++ sstream library for file string parsing functionality
#include <sstream>
//Includes the C++ vector library for vector manipulation and implementation
#include <vector>
//Using standard namespace to avoid using std:: prefix
using namespace std;




bool is_file_valid(string double_number_text_file){
    ifstream valid_double_numbers_file(double_number_text_file);
    if(valid_double_numbers_file.is_open(){
        return true;
    }
    else{
        valid_double_numbers_file.close();
        return false;
    }
}

vector<string> load_double_numbers_from_file(string double_number_text_file){
    ifstream valid_double_numbers_file(double_number_text_file);
    vector<string> double_numbers;
    if 
}



int main(){
    string double_number_text_file;
    cout << "Enter the name of the double number text file: ";
    cin >> double_number_text_file;
    if(is_file_valid(double_number_text_file)){
        cout << "The file is valid." << "\n";
    }
    else{
        cout << "The file is not valid." << "\n";

    }








    return 0;
}