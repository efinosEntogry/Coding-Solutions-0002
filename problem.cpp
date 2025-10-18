#include <iostream>

using namespace std;

bool isStrongPassword(string password, string & trialPrompt);

int main() {

    string password, trialPrompt = "Missing ";

    cout << "Enter password: ";
    cin >> password;

    cout << (isStrongPassword(password, trialPrompt) ? "Strong password" : trialPrompt);

    return 0;
}

bool isStrongPassword(string password, string & trialPrompt) {

    bool passwordLength = false, uppercase = false, lowercase = false, digit = false, symbol = false;

    int lowercaseLetters = 0, uppercaseLetters = 0, digits = 0, symbols = 0;

    if (password.length() >= 8) {
        passwordLength = true;
    }else {
        trialPrompt += " enough characters";
    }

    for (int i = 0; i < password.length(); ++i) {
        if (password.at(i) >= 65 && password.at(i) <= 90) {
            uppercaseLetters++;
        }
        if (password.at(i) >= 97 && password.at(i) <= 122) {
            lowercaseLetters++;
        }
        if (password.at(i) >= 48 && password.at(i) <= 57) {
            digits++;
        }
        if (password.at(i) >= 33 && password.at(i) <= 47) {
            symbols++;
        }
    }

    if (!uppercaseLetters) {
        trialPrompt += " & uppercase letters";
    }else {
        uppercase = true;
    }
    if (!lowercaseLetters) {
        trialPrompt += " & lowercase letters";
    }else {
        lowercase = true;
    }
    if (!digits) {
        trialPrompt += " & digits";
    }else {
        digit = true;
    }
    if (!symbols) {
        trialPrompt += " & symbols";
    }else {
        symbol = true;
    }

    if (passwordLength && uppercase && lowercase && digit && symbol) {
        return true;
    }else {
        return false;
    }
}
