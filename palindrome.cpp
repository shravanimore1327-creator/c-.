/*
Name - Shravani More
Practical 8  - Palindrome using Standard template library (STL) stack
*/

#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

string cleanedString(const string& input) {
  string cleaned = " ";
  for (char c : input) {
    if (isalnum(c)) cleaned += tolower(c);
  }
  return cleaned;
} 

void printOriginalandReversed(const string& input) {
  stack<char> s;
  string cleaned = cleanedString(input);

  for (char c : cleaned) s.push(c);

  cout << "\nOriginal String:" << input << endl;
  cout << "Reversed String:\n";
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << endl;
}

bool isPalindrome(const string& input) {
  string cleaned = cleanedString(input);
  stack<char> s;
  for (char c : cleaned) s.push(c);
  for (char c : cleaned) {
    if (c != s.top()) return false; 
        s.pop();
  }
  return true;
}

int main() {
  string input;
  cout << "Enter the string:\n";
  getline(cin, input);

  printOriginalandReversed(input);

  if (isPalindrome(input)) {
    cout << "Given string is palindrome.\n";
  } else {
    cout << "Given string is not palindrome.\n";
  }
  return 0;
}
