#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <limits> // add this header to use numeric_limits
using namespace std;

class Data{
    public:
        string username, email, password;
        fstream file;
};

Data user;


// Function to trim leading and trailing whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to convert string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to remove trailing non-alphanumeric characters
string cleanPassword(const string& str) {
    size_t last = str.find_last_not_of(" \t\n\r\f\v.");
    if (last == string::npos) return "";
    return str.substr(0, last + 1);
}

void login() {
    string searchName, searchPass;
    cout << "-------------LOGIN-------------" << endl;
    cout << "Enter your user name :: ";
    getline(cin, searchName);
    cout << "Enter your password :: ";
    getline(cin, searchPass);

    user.file.open("UserData.txt", ios::in);  // Opens the file for reading

    if (user.file.is_open()) {
        bool loginsuccessful = false;
        string fileLine;

        while (getline(user.file, fileLine)) {
            // Debug: Print the raw line from the file
            cout << "Raw line from file: " << fileLine << endl;

            // Parse the line from the file
            size_t firstDelimiter = fileLine.find('*');
            size_t secondDelimiter = fileLine.find('*', firstDelimiter + 1);
            
            if (firstDelimiter != string::npos && secondDelimiter != string::npos) {
                user.username = fileLine.substr(0, firstDelimiter);
                user.email = fileLine.substr(firstDelimiter + 1, secondDelimiter - firstDelimiter - 1);
                user.password = fileLine.substr(secondDelimiter + 1);

                // Clean and trim whitespace
                user.username = toLower(trim(user.username));
                user.password = cleanPassword(trim(user.password));  // Clean trailing characters
                searchName = toLower(trim(searchName));
                searchPass = cleanPassword(trim(searchPass));  // Clean trailing characters

                // Debug: Print the trimmed and cleaned values
                cout << "Trimmed & Lowercase Username: " << user.username << endl;
                cout << "Cleaned & Lowercase Password: " << user.password << endl;
                cout << "Trimmed & Lowercase Search Name: " << searchName << endl;
                cout << "Cleaned & Lowercase Search Password: " << searchPass << endl;

                // Check if the credentials match
                if (searchName == user.username && searchPass == user.password) {
                    loginsuccessful = true;
                    cout << "Login successful!" << endl;
                    cout << "\nWELCOME " << user.username << endl;
                    cout << "EMAIL :: " << user.email << endl;
                    break;  // Exit the loop if login is successful
                }
            }
        }

        if (!loginsuccessful) {
            cout << "Login failed: username or password incorrect." << endl;
        }

        user.file.close();
    } else {
        cout << "Failed to open file." << endl;
    }
}

void signup(){
    cout <<"Enter Your User Name :: ";
    getline(cin, user.username);
    cout << "Enter Your Email address ::";
    getline(cin, user.email);
    cout << "Enter Your Password ::";
    getline(cin, user.password); 
    
    
    user.file.open("UserData.txt", ios :: out | ios :: app);  //Opens the file for writing (ios::out). Ensures that all data written is appended to the end (ios::app).

    //error to handle the file opening
    if(user.file.is_open()) {
        user.file << user.username << "*" << user.email << "*" << user.password << "." << endl;
        user.file.close();
        cout << "Data Saved Successfully." << endl;
    }
    else{
        cout <<"Failed to open the file." << endl;
    }
}

void forp(){
    bool correct = false;
    string searchname, searchmail;
    cout << "Enter your user name ::";
    getline(cin, searchname);
    cout << "Entery yor email ::";
    getline(cin, searchmail);
    
    user.file.open("UserData.txt", ios :: in);

    if(user.file.is_open()) {
        while(getline(user.file, user.username, '*')){
            getline(user.file, user.email, '*');
            getline(user.file, user.password, '\n');

            if(searchname == user.username && searchmail == user.email){
                correct = true;
                cout <<"GREAT ACCOUNT FOUND." << endl;
                cout << "Welcome " << user.username << endl;
                cout << "PASSWORD :: " << user.password << endl;
                break;
            }
        }
        if(!correct){
            cout << "incorrect username or email" <<endl;
        }
        user.file.close();
    }
    else{
        cout <<"Failed to open file." << endl;
    }
}


int main(){
    int option;
    cout << "1- login" << endl;
    cout << "2- Sign-up" << endl;
    cout << "3- forgot Password" << endl;
    cout << "4- Exit" << endl;;
    cout << "Enter your option:: ";
    cin >> option;

    //clear the input buffer after reading optin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(option){
        case 1:
        login();
        break;

        case 2:
        signup();
        break;

        case 3:
        forp();
        break;

        case 4:
        exit(0);
        break;

        default:
        cout << "INVALID OPTION";
    }
    return 0;
}