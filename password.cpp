#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool isSpecialCharacter(char c) {
    string specialCharacters = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~\\";
    return specialCharacters.find(c) != string::npos;
}


int calculatePasswordStrength(const string& password) {
    int strength = 0;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    bool hasUpperCase = false;
    bool hasLowerCase = false;

    if (password.length() >= 6) {
        strength += 20; 
    }
    
    if (password.length() > 6) {
        strength += 20;  
    }

    for (char c : password) {
        if (isdigit(c)) hasDigit = true;
        if (isSpecialCharacter(c)) hasSpecialChar = true;
        if (isupper(c)) hasUpperCase = true;
        if (islower(c)) hasLowerCase = true;
    }

    if (hasDigit) strength += 20;
    if (hasSpecialChar) strength += 20;
    if (hasUpperCase) strength += 20;
    if (hasLowerCase) strength += 20;

    return strength;
}

int main() {
    string password;
    cout << "Enter your password: ";
    getline(cin, password);

    int strength = calculatePasswordStrength(password);

    cout << "Password Strength: " << strength << "%" << endl;

    return 0;
}
