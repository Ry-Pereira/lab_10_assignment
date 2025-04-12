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
    if(valid_double_numbers_file.is_open()){
        return true;
    }
    else{
        valid_double_numbers_file.close();
        return false;
    }
}


bool is_a_valid_numeber(char character){
    if(character >= 0 && character <= 9){
        return true;
    }
    else
}


bool is_a_valid_character(char character){
    if(character == "." || character == "-" || character == "+"{
        return true;
    }
    else{
        return false;
    }
}



double parse_number(const string &expression){
    int index = 0;
    int expression_length = expression.length();
    int decimal_points_found = 0;
    double number = 0.0;
    bool is_positive = true;
    bool is_negative = false;
    bool is_decimal = false;

    if (expression[index] == '-'){
        is_negative = true;
        is_positive = false;
        index++;
    }
    else if(expression[index] == '+'){
        is_positive = true;
        index++;
    }

    for(index;index<expression_length;index++){}{
        if(expression[index] == '.'){
            is_decimal = true;
            decimal_points_found++;
            index++;
        }
        if(is_decimal){
        }
        if(decimal_points_found > 1){
            cout<<"Invalid double number"<<endl;
            return 0.0;
        }

    }    
}


void add_parsed_number(vector<double> &double_numbers){
    index = 0;
    double sum = 0.0;
    for(index;index<double_numbers.size();index++){
        sum = doubles_numbers[index] + -123.456;
        cout<<"Sum of: "<<double_numbers[index]<<" + -123.456 = "<<sum<<"\n";
    }
}

vector<string> load_double_numbers_from_file(string double_number_text_file){
    ifstream valid_double_numbers_file(double_number_text_file);
    vector<string> double_numbers;
    if(valid_double_numbers_file.is_open()){
        string line;
        while(getline(valid_double_numbers_file,line)){
            if(line.size() != 0){
                stringstream ss(line);
                string value;
                int i = 0;
                while(ss >> value){
                    i++;
                }
                if(i == 1){
                    stringstream bb(line);
                    string valuer;
                    while(bb >> valuer){
                        cout<<"Value "<<valuer;
                        double_numbers.push_back(valuer);
                }
                else{
                    cout<<"Only one double number can occupy a line"<<"\n";
                }
                }
                
                cout<<"\n";
            }
        }
    } 
    return double_numbers;
}



int main(){
    string double_number_text_file;
    vector<string> double_numbers_list;

    cout << "Welcome to the double number program" << "\n";
    cout << "This program will read a double number text file and parse the double numbers in it" << "\n";
    cout << "Enter the name of the double number text file: ";
    cin >> double_number_text_file;
    if(is_file_valid(double_number_text_file)){
        cout << "The file is valid." << "\n";
        
        double_numbers_list = load_double_numbers_from_file(double_number_text_file);
        add_parsed_number(double_numbers_list);
    }
    else{
        cout << "The file is not valid." << "\n";

    }

    cout<<"Goodbye"<<"\n";
    cout<<"Program Has Ended"<<"\n";
    return 0;
}