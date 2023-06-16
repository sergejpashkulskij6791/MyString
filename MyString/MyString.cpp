#include <iostream>
#include <cstring>
using namespace std;
class MyString {
private:
    char* str;
    int size;

public:
    // Default constructor
    MyString() {
        size = 80;
        str = new char[size + 1]; // +1 for a '\0' character at the end of a string
    }

    //Constructor for creating a string of arbitrary size
    MyString(int length) {
        size = length;
        str = new char[size + 1];
    }

    // Constructor that initializes a string with a value received from the user
    MyString(const char* inputStr) {
        size = strlen(inputStr);
        str = new char[size + 1];
        strcpy_s(str,size, inputStr);
       // strcpy(str, inputStr);
    }

    // copy constructor
    MyString(const MyString& other) {
        size = other.size;
        str = new char[size + 1];
        strcpy_s(str, size, other.str);
    }

    //Method for entering a string from the keyboard
    void InputString() {
        cout << "Enter the string: ";
        cin.getline(str, size + 1);
    }

    //Method for displaying a string on the screen
    void OutputString() const {
        cout << "Line: " << str << endl;
    }

    //Method for getting string length
    int Length() const {
        return strlen(str);
    }

    // Method for checking if a string starts with a given character
    bool StartsWith(char ch) const {
        return str[0] == ch;
    }

    // Method for checking if a string ends with a given character
    bool EndsWith(char ch) const {
        int len = strlen(str);
        return len > 0 && str[len - 1] == ch;
    }

    //Method for comparing a string with a given C-string
    bool Equal(const char* otherStr) const {
        return strcmp(str, otherStr) == 0;
    }

    //Method for getting a pointer to a string
    const char* GetStr() const {
        return str;
    }

    // Method for setting string value
    void SetStr(const char* newStr) {
        delete[] str; // Freeing up old memory
        size = strlen(newStr);
        str = new char[size + 1];
        strcpy_s(str, size, newStr);
    }

    // Destructor
    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString s1; // Create a 80 character string
    s1.InputString(); // Entering a string from the keyboard
    s1.OutputString(); //Printing a string to the screen

    MyString s2(50); // Create a 50 character string
    s2.InputString();
    s2.OutputString();

    MyString s3("Hello"); // Creating a String and Initializing it with a Value
    s3.OutputString();

    MyString s4(s3); // Create a string from an existing string
    s4.OutputString();

    cout << "String length s4: " << s4.Length() << endl;
    cout << "The string s4 starts with the character 'H': " << s4.StartsWith('H') << endl;
    cout << "The string s4 ends with an 'o': " << s4.EndsWith('o') << endl;
    cout << "The string s4 is \"Hello\": " << s4.Equal("Hello") << endl;

    const char* strPtr = s4.GetStr(); // Getting a pointer to a string
    cout << "Pointer to string s4: " << strPtr << endl;

    s4.SetStr("New String"); // Change the value of a string
    s4.OutputString();

    return 0;
}
