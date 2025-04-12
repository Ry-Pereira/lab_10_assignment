//Program Name: Lab 10: Basic Double Number Calculator
//Brief Description: The program takes in a double number text file from the user, validate it, and parse it and add a specific double number to it.
//Input: The input will be a double sttring number text file from the user
//Ouput: The ouput will welcome the user and give a goodbye message to the user. The output will show that the text file is valid or not. The output parse the double numbers and add a specific number to it and display the result to terminal/
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



//Function that takes in a double number text file, and tries to open it, and returns true or false if they can open it or not
bool is_file_valid(string double_number_text_file){
    //Declare and initialize input file stream object name valid double number file with double number text file passed as argument
    ifstream valid_double_numbers_file(double_number_text_file);
    //If the valid double number file is able to be opened, the file is valid
    if(valid_double_numbers_file.is_open()){
        //Returns true if the file is opened, because it is valid
        return true;
    }
    //If the valid double number file is unable to open, the file is not valid
    else{
        //Closes the valid double number file
        valid_double_numbers_file.close();
        //Returns false if the file is not opened, because the file is not valid
        return false;
    }
}

//Function that takes in a character character and returns true or false if the character is a valid number or not
bool is_a_valid_numeber(char character){
    //Checks if the character is a number by seeing it if equal to or bewteen 0 and 9, and returns true or false if it is a number or not
    if(character >= 0 && character <= 9){
        //Returns true if the character is a number
        return true;
    }
    //If the characrer does not meet these conditions, its not a number
    else{
        //Returns false to indicate it is not a valid number
        return false;
    }
}

//Function that takes in a character character and returns true or false if the character is either ., or -, or +. To indcate its either of these math operators
bool is_a_valid_character(char character){
    //If the character is equal to .,-,+ it is not a valid math operator
    if(character == '.' || character == '-' || character == '+'{
        //Returns true to indicate it is a valid math operator
        return true;
    }
    //If the character does not meet these condition, its not a math operator
    else{
        //Returns false to indicate it is not a valid math operator
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
    int index = 0;
    double sum = 0.0;
    for(index;index<double_numbers.size();index++){
        sum = doubles_numbers[index] + -123.456;
        cout<<"Sum of: "<<double_numbers[index]<<" + -123.456 = "<<sum<<"\n";
    }
}


//Function to take in a string double number text file as argument, and loads the double numbers from file and returns a vector of double numbers
vector<string> load_double_numbers_from_file(string double_number_text_file){
    //Declare and initialize input file stream object name valid double number file with double number text file passed as argument
    ifstream valid_double_numbers_file(double_number_text_file);
    //Declare and initializes a vector of string double numbers to store the double numbers in the file
    vector<string> double_numbers;
    //If the valid double number file is able to be opened
    if(valid_double_numbers_file.is_open()){
        //Declares string line to store the file line string
        string line;
        //Continously in the file, to get the lien from the file and store it in the string line
        while(getline(valid_double_numbers_file,line)){
            //If the line is not empty
            if(line.size() != 0){
                //Declares and initializes a string stream object with line passed in
                stringstream ss(line);
                //Declares string value to store the string value of line
                string value;
                //Declares integer i to 0
                int i = 0;
                //Loopes through each element in the line until there is no more elemenets left and stores it in the value
                while(ss >> value){
                    //I is incremented by 1
                    i++;
                }
                //If i is equal to 1, thene there is only one number in the line, so it can be added, since that is the requirement
                if(i == 1){
                    //Declares and initializes a string stream object with line passed in
                    stringstream bb(line);
                    //Declares string value to store the string value of line
                    string valuer;
                    //Loopes through each element in the line until there is no more elemenets left and stores it in the value
                    while(bb >> valuer){
                        //double number pushed the value into the back of the vector double numbers
                        double_numbers.push_back(valuer);
                }
                //If the i is not equal to 1, then there is more than one number occupying the line, so it can't be added
                else{
                    //Prtints to terminal that only one double number can occupy a line, so it won't be added.
                    cout<<"Only one double number can occupy a line"<<"\n";
                }
                //Prints newline spacing
                cout<<"\n";
            }
        }
    } 
    //Reurns the vector of double numbers
    return double_numbers;
}


//Main function that is the entry point into the programm.
int main(){
    //Declares string double number text file to store the double number text file name from user
    string double_number_text_file;
    //Declares vectore string to store the double number in the file as a list
    vector<string> double_numbers_list;

    //Prints to terminal to welcome to the user to program and give instrustction on how to use it
    cout << "Welcome to the double number program" << "\n";
    cout << "This program will read a double number text file and parse the double numbers in it" << "\n";

    //Prints to terminal to user to prompt for a the text file namae to be entered
    cout << "Enter the name of the double number text file: ";
    //Stores the user input in double number text file
    cin >> double_number_text_file;
    //If the file is valud, with the double number text file passed in, then the file is valid, for coninueing the program
    if(is_file_valid(double_number_text_file)){
        //Stores the double numbers in the file to the vector double numbers list, with double number text file argument passed in
        double_numbers_list = load_double_numbers_from_file(double_number_text_file);
        //Executes the add parsed number function with double numbers list passed in as argument to add the double numbers in the file with a specific double number
        add_parsed_number(double_numbers_list);
    }
    //If the file is not valid, there will be no continuation of the program, and it will end
    else{
        //Prints to terminal that the file is not valid
        cout << "The file is not valid." << "\n";

    }

    //Prints to terminal that the program has ended and goodbye message to user
    cout<<"Goodbye"<<"\n";
    cout<<"Program Has Ended"<<"\n";

    
    //Returns 0 to indicate the program has ended successfully
    return 0;
}