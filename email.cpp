
#include <iostream>
#include <regex>
#include <string>
using namespace std;


bool is_valid_email(const string& email) {
    // Define the regular expression pattern for a valid email
    regex email_pattern("[a-zA-Z0-9]+.@\\w+.com");
    
    // Use regex_match to check if the email string matches the pattern
    if (regex_match(email, email_pattern)) {
        return true;
    } else {
        return false;
    }
}
bool is_valid_password(const string& password) {
    // Define the regular expression pattern for a valid password
    regex password_pattern("(?=.*[A-Z])(?=.*[a-z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}");
    
    // Use regex_match to check if the password string matches the pattern
    if (regex_match(password, password_pattern)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string email, password;
    cout<<"Enter email : "<<endl;
    cin>>email;
    cout<<"Enter password"<<endl;
    cin>>password;
    if(is_valid_email(email))
    cout<<"valid email"<<endl;
    else 
    cout<<"Invalid email"<<endl;
    if(is_valid_password(password)){
        cout<<"valid password "<<endl;
        exit(1);
    }
    else{
        cout<<"Invalid password"<<endl;

    }
    

    return 0;
}