//Program Name: Lab 10: Basic Double Number Calculator
//Brief Description: The program takes in a double number text file from the user, validate it, and parse it and add a specific double number to it.
//Input: The input will be a double sttring number text file from the user
//Ouput: The ouput will welcome the user and give a goodbye message to the user. The output will show that the text file is valid or not. The output parse the double numbers and add a specific number to it and display the result to terminal/
//All collaborators: None
//Other Sources:Github Copilot and ChatGPT 
//Author: Ryan Antony Pereira
//Creation Date: 4/12/2025
//Last Modified Date: 4/15/2025

//Includes the iostream library file to include standard input and ouput for cin and cout
#include <iostream>
//Includes the C++ fstream libary for file input and output, open and close functionality
#include <fstream>
//Includes the C++ sstream library for file string parsing functionality
#include <sstream>
//Includes the C++ vector library for vector manipulation and implementation
#include <vector>
#include <cmath>
#include <iomanip>
//Using standard namespace to avoid using std:: prefix
using namespace std;



//Function that takes in a double number text file, and tries to open it, and returns true or false if they can open it or not
bool is_file_valid(string double_number_text_file){
    //Declare and initialize input file stream object name valid double number file with double number text file passed as argument
    ifstream valid_double_numbers_file(double_number_text_file);
    //If the valid double number file is able to be opened, the file is valid
    return valid_double_numbers_file.is_open();
}

//Function that takes in a character character and returns true or false if the character is a valid number or not
bool is_a_valid_number(char character){
    //Checks if the character is a number by seeing it if equal to or bewteen 0 and 9, and returns true or false if it is a number or not
    return character >= '0' && character <= '9';
}

//Function that takes in a character character and returns true or false if the character is either ., or -, or +. To indcate its either of these math operators
bool is_a_valid_character(char character){
    //If the character is equal to .,-,+ it is not a valid math operator
    return character == '.' || character == '-' || character == '+';
}


//Function to check if the string is a valid double value, will return string valid or invalid to indicate if the double number is a valid double number
string is_valid_double_at_start(string expression){
    //If expression at index 0 is a valid character or a valid number the program continues
    if(is_a_valid_character(expression[0]) == 1 ||is_a_valid_number(expression[0]) == 1){
        //If the expression at index 0 is equal to 0
        if(expression[0] == '.'){
            //Checks to see if the element after the expression is a valid number
            if(is_a_valid_number(expression[1]) != 1){
                //Returns invalid because there has to be a valid numbe after the decimal point
                return "invalid";
            }
            //Loops through the rest of the string to check for mutliple instances of decimal points
            for(int index = 1;index < expression.length();index++){
                //If the expression at index equals a dot, there is a decimal point
                if(expression[index] == '.'){
                    //Returns invalid to indicate there are multiple decimal points which is invalid
                    return "invalid";
                }
            }
            //If doesn't meet these conditions then it is a valid double number
            return "valid";
        }
        //If expression at index 0 is equal to +
        if(expression[0] == '+'){
            //Loops through the rest of the expression
            for(int index = 1;index < expression.length();index++){
                //If the expression at index is equal to +, then there are mutliple plus signs
                if(expression[index] == '+'){
                    //Returns invalid to indcate there are mutliple plus sign values
                    return "invalid";
                }
            }
            //Returns valid to indicate it passed all checks, is a valid oduble number at the start
            return "valid";
        }
        //If the expression at index 0 is equal to -
        if(expression[0] == '-'){
        //Loops through the rest of the expression
         for(int index = 1;index < expression.length();index++){
                //If the expression at index is equal to -, there are multiple minus signs
                if(expression[index] == '-'){
                    //Returns invalid to indicate there are multiple minues signs in the oduble number
                    return "invalid";
                }
            }
            //Returns valid to indicate it passed all the checks
            return "valid";
        }
        //If the expression at index 0, is not any of these sign, its just a number, its valid
        else{
            //Returns valid to indicate its a vlaid number
            return "valid";
        }
    }
    //Returns invalid to indicate the double number is valid if it not of any of the signs
    return "invalid";
}
    

//Function for furhter checking the body of the double number to check if its valid or not, will return true or false to indcate that
bool is_valid_double_body(string expression){
    //Declares and initializes is valis to true
    bool is_valid = true;
    //Declares amount of point to 0 to indcate the number of decimal points found in the double number body
    int amount_of_decimal_points = 0;
    
    //Loops through the expression at each index
    for(int index = 1;index < expression.length(); index++){
        //If the expression at index is -, its false, it needs to show up at the first index
        if(expression[index] == '-'){
            //Is valud is set to false to indicate that the double number body invalid because a sign is in the body
            is_valid =  false;
        }
        //If the expression at index is + its false, it needs to show up at the first index
        if(expression[index] == '+'){
             //Is valud is set to false to indicate that the double number body invalid because a sign is in the body
            is_valid =  false;
        }
        //If the expression at index is .
        if(expression[index] == '.'){
            
            //If the expression at index + 1 is a valid number, to indicate that a real number needs to be front of a decimal
            if(is_a_valid_number(expression[index+1]) != 1){
                 //Is valud is set to  false to indicate that there is no real number in front of the decimal.
                is_valid =  false;
            }
            //If the there is a number in front of the decimal, it valid in the sense
            else{
                //Increments amount of decimal points
                amount_of_decimal_points++;
            }
            
        }
        //If the amount of decimal points is greater than 1, then there are multiple decimal points in the double number
        if(amount_of_decimal_points >1){
            //Is valid is set to false, to indicate there are multiple decimal points in the double number body
            is_valid = false;
        }
    }
    
    //If the is valis is true, the double number obdy is valid
    if(is_valid == true){
        //Returns true to indcate that is a true double number
        return true;
    }
    //If is valid is false, the double number body is not valid
    else{
        //Returns false to indicate its a invalid double number
        return false;
    }
    //Provides newline spacing
    cout<<"\n";
}


//Function to add the specific double number -123.456 to the valid expression passed in as a string
void add_specific_double_number(string expression){
    //Declares double type sum to 0.0
    double sum = 0.0;
    //Initialzzies the string left and right to hold the left and right part of the expression that is split by the decimal point
    string left_double_substring;
    string right_double_substring;

    //Declares the integer point position to hold the integer position of the decimal point in the double number
    int decimal_point_position;
    //Declares and initializes is decimal point present to false to indicate if the decimal point is present in the odube number
    bool is_decimal_point_present = false;
    //Declares string symbol type to hold the symbol type of a number
    string symbol_type;
    
    //If the expression at index 0 is +, the number is positive
    if(expression[0] == '+'){
        //Symbol type is set to positive
        symbol_type = "positive";
    }
    //If the expression at index 0 is -, the number is negative
    else if(expression[0] == '-'){
        //Symbol type is set to negative
        symbol_type = "negative";
    }
    //else the number is positive regardless of symbol in fron of it
    else{
        //Symbol type is set to positive
        symbol_type = "positive";
    }
    
    
    //For in loop to iterate through each element in the expression
    for(int index = 0;index<expression.length();index++){
        //If the expression at index is a decimal point
        if(expression[index] == '.'){
            //Is decimal point present is set to true to indcate there is a decimal point in the double number
            is_decimal_point_present = true;
        }
    }
    //If the is dot present is true
    if(is_decimal_point_present == true){
        //Decimal point position is set to the found position of the decimal point in the double number
        decimal_point_position = expression.find('.');
        //Left substring is set to the substring before the decimal point position
        left_double_substring = expression.substr(0,decimal_point_position);
        //Right substring is set to the substring before the decimal point position
        right_double_substring = expression.substr(decimal_point_position,expression.length());
    }
    //If the dot is not present, there is only a present left string
    else{
    //Left substring set to the expression
    left_double_substring = expression;
    //Right substring is set to the 00
    right_double_substring = "00";
    }
    
    //For in loop through each elment in the left oduble substring
    for(int i = 0; i < left_double_substring.length(); i++){
        //Does a switch case of the left double substring at index
        switch(left_double_substring[i]){
            //If the case is string 0
            case '0':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 0 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 0 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 1
            case '1':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 1 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 1 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 2
            case '2':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 2 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 2 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 3
            case '3':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 3 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 3 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 4
            case '4':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 4 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 4 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 5
            case '5':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 5 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 5 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 6
            case '6':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 6 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 6 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 7
            case '7':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 7 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 7 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 8
            case '8':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 8 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 8 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
            //If the case is string 9
            case '9':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum+= 9 * pow(10,left_double_substring.length() - i-1);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the multiplication of 10 to the power of the left double sbstring length  minus the index and 1
                sum-= 9 * pow(10,left_double_substring.length() - i-1);
            }
            //Breaks out of switch case
            break;
        }
        
    }

    for(int i = 0; i < right_double_substring.length(); i++){
        switch(right_double_substring[i]){
            //If the case is string 1
            case '0':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 0 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 0 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 1
            case '1':
            //If the symbol type is positive, its a positive double number
             if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 1 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 1 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 2
            case '2':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 2 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 2 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 3
            case '3':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 3 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 3 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 4
            case '4':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 4 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 4 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 5
            case '5':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 5 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 5 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 6
            case '6':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 6 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 6 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 7
            case '7':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 7 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 7 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 8
            case '8':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 8 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 8 / pow(10,i);
            }
            //Breaks out of switch case
            break;
            //If the case is string 9
            case '9':
            //If the symbol type is positive, its a positive double number
            if(symbol_type == "positive"){
                //Sum increments the number integer of the case to the division of 10 to the power of value i
                sum+= 9 / pow(10,i);
            }
            //If not the double number is negative
            else{
                //Sum decrements the number integer of the case to the division of 10 to the power of value i
                sum-= 9 / pow(10,i);
            }
            //Breaks out of switch case
            break;
        }
        
    }
    
    //Sum is decremented by 100.000
    sum -= 100.000;
    //Sum is decremented by 20.000
    sum -= 20.000;
    //Sum is decremented by 3.000
    sum -= 3.000;
    //Sum is decremented by .400
    sum -= .400;
    //Sum is decremented by .050
    sum -= .050;
    //Sum is decremented by .006
    sum -= .006;
    //Declares and initializes set fixed to the right double substring length + 3, to set the precision for the uput for the resutl printing format
    int set_fixed = right_double_substring.length();
    //Prints the result to terminal otput fixes, with set precsion of the result so we wount get a double number at scientific notation
    cout<<expression<<" + "<<-123.456<<" = "<<std::fixed<<setprecision(set_fixed)<<sum<<"\n";
}

//Function for taking a in a vector string of doubel numbers,sees if there valid, and prints the ouput of them added with a specific double number
void add_parsed_number(vector<string> double_numbers){
    //Loops throguh each double number number in the vector string
    for(int index =0;index<double_numbers.size();index++){
        //Declares and initializes string valid double to the output result of the isvalid double at start with double number at index
        string valid_double = is_valid_double_at_start(double_numbers[index]);
        //If valid double is not invalid
        if(valid_double != "invalid"){
            //If the is valid double body with double number at index passed is true, it can now finally be added with the specific double number
            if(is_valid_double_body(double_numbers[index]) == 1){
                //Executes the add specific double number with double number with index passed in as argument
                add_specific_double_number(double_numbers[index]);
            }
        }
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
            if(line.size()-1 == 0){
                continue;
            }
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
