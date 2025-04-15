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
#include <cmath>
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



string is_valid_double(string expression){

   

    if(is_a_valid_character(expression[0]) == 1 ||is_a_valid_number(expression[0]) == 1){
        if(expression[0] == '.'){
            if(is_a_valid_number(expression[1]) != 1){
                return "invalid";
            }
            for(int index = 1;index < expression.length();index++){
                if(expression[index] == '.'){
                    return "invalid";
                }
            }
            return "decimal";
        }
        if(expression[0] == '+'){
            for(int index = 1;index < expression.length();index++){
                if(expression[index] == '+'){
                    return "invalid";
                }
            }
            return "positive";
        }
        if(expression[0] == '-'){
         for(int index = 1;index < expression.length();index++){
                if(expression[index] == '+'){
                    return "invalid";
                }
            }
            return "negative";
        }
        else{
            return "positive";
        }
    }
    return "invalid";
}
    
bool pot(string expression){
    bool is_valid = true;
    int amount_of_points = 0;
    
    
    for(int index = 1;index < expression.length(); index++){
        if(expression[index] == '-'){
            is_valid =  false;
        }
        if(expression[index] == '+'){
            is_valid =  false;
        }
        if(expression[index] == '.'){
          
            if(is_a_valid_number(expression[index+1]) != 1){
                is_valid =  false;
            }
            else{
                amount_of_points++;
            }
            
        }
        if(amount_of_points >1){
            is_valid = false;
        }
    }
    
    if(is_valid == true){
        return true;
    }
    
    cout<<"\n";
}

double add_it_up(string expression){
    double sum = 0.0;
  
    bool is_dot_present = false;
    for(int index = 0;index<expression.length();index++){
        if(expression[index] == '.'){
            is_dot_present = true;
        }
    }
    if(is_dot_present == false){
    
        return 0.0;
    }
    int dot1 = expression.find('.');
    string left = expression.substr(0,dot1);
    string right = expression.substr(dot1,expression.length());
    //cout<<"Left"<<left<<left.length()<<"\n";
    //cout<<"Rightt"<<right<<"\n";
    
    char sign = left[0];
    int bet = 3;
    for(int i = 0; i < left.length(); i++){
        switch(left[i]){
            case '0':
            sum+= 0 * pow(10,left.length() - i-1);
            break;
            case '1':
            sum+= 1 * pow(10,left.length() - i-1);
            break;
            case '2':
            cout<< 2<<"\n";
            sum+= 2 * pow(10,left.length() - i-1);
            break;
            case '3':
            cout<< 3<<"\n";
            sum+= 3 * pow(10,left.length() - i-1);
            break;
            case '4':
            cout<< 4<<"\n";
            sum+= 4 * pow(10,left.length() - i-1);
            break;
            case '5':
            cout<< 5<<"\n";
            sum+= 5 * pow(10,left.length() - i-1);
            break;
            case '6':
            cout<< 6<<"\n";
            sum+= 6 * pow(10,left.length() - i-1);
            break;
            case '7':
            cout<< 7<<"\n";
            sum+= 7 * pow(10,left.length() - i-1);
            break;
            case '8':
            cout<< 8<<"\n";
            sum+= 8 * pow(10,left.length() - i-1);
            break;
            case '9':
            cout<< 9<<"\n";
            sum+= 9 * pow(10,left.length() - i-1);
            break;
        }
        
    }

    for(int i = 0; i < right.length(); i++){
        switch(right[i]){
            case '0':
            sum+= 0 / pow(10,i);
            break;
            case '1':
            sum+= 1 / pow(10,i);
            break;
            case '2':
            cout<< 2<<"\n";
            sum+= 2/ pow(10,i);
            break;
            case '3':
            cout<< 3<<"\n";
            sum+= 3 / pow(10,i);
            break;
            case '4':
            cout<< 4<<"\n";
            sum+= 4 / pow(10,i);
            break;
            case '5':
            cout<< 5<<"\n";
            sum+= 5 / pow(10,i);
            break;
            case '6':
            cout<< 6<<"\n";
            sum+= 6 / pow(10,i);
            break;
            case '7':
            cout<< 7<<"\n";
            sum+= 7 / pow(10,i);
            break;
            case '8':
            cout<< 8<<"\n";
            sum+= 8 / pow(10,i);
            break;
            case '9':
            cout<< 9<<"\n";
            sum+= 9 / pow(10,i);
            break;
        }
        
    }
    
    sum -= 100.000;
    sum -= 20.000;
    sum -= 3.000;
    sum -= .400;
    sum -= .050;
    sum -= .006;
    cout<<expression<<'+'<<-123.456<<'='<<"Sum: "<<sum<<"\n";
    
    return 0.0;
    
    
}


void add_parsed_number(vector<string> double_numbers){
    string sum;
    for(int index =0;index<double_numbers.size();index++){
        string valid_double = is_valid_double(double_numbers[index]);
        if(valid_double != "invalid"){
            if(pot(double_numbers[index]) == 1){
                
                add_it_up(double_numbers[index]);
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