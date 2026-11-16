/*
Shravani More 
Practical 1 - (DSA) Write a menu driven C++ program of who participated in coding, project, mastermind, paper presentation,
In coding and project; in coding or project or both / mastermind; in coding but not in mastermind.
*/ 

#include <iostream>
#include <string>
using namespace std;


class Student {
public: 
     string code[10], project[10], mastermind[10], paper[10];
     int i, j, k, m, s1, s2, s3, s4;

public:
void getData() {
    cout << "Enter the number of students participated in coding competition:\n";
    cin >> s1;
    cout << "Enter the names of students participated in coding competition:\n";
    for (i = 0; i < s1; i++) cin >> code[i];
 
    cout << "Enter the number of students participated in project competition:\n";
    cin >> s2;
    cout << "Enter the names of students participated in project competition:\n";
    for (j = 0; j < s2; j++) cin >> project[j];
  
    cout << "Enter the number of students participated in mastermind:\n";
    cin >> s3;
    cout << "Enter the names of students participated in mastermind:\n";
    for (k = 0; k < s3; k++) cin >> mastermind[k];

    cout << "Enter the number of students participated in paper presentation:\n";
    cin >> s4;
    cout << "Enter the names of students participated in paper presentation:\n";
    for (m = 0; m < s4; m++) cin >> paper[m];
    cout << endl;
 }


void second() {                     // Coding and Project
     cout << "Enter the names who participated in coding and project competition:\n";
     for (i = 0; i < s1; i++) {
         for  (j = 0; j < s2; j++) {
             if (code[i] == project[j]) 
               cout << code[i] << " ";
               cout << endl;
         }
     }
 }


void third() {                      //Coding or Project
     cout << "Enter the names who participated in coding or project competition:\n";
      for (i = 0; i < s1; i++) cout << code[i] << " ";
      for (j = 0; j < s2; j++) {
        bool is_present = false;
        for (i = 0; i < s1; i++) if (code[i] == project[j]) is_present = true;
              if (!is_present) cout << project[j] << " ";
              cout << endl;
    } 
}



void fourth() { 
    cout << "Members who have participated in coding but not in mastermind:\n";
    for (i = 0; i < s1; i++) {
        bool in_mastermind = false;
        for (k = 0; k < s3; k++) if (code[i] == mastermind[k]) in_mastermind = true;
              if (!in_mastermind) cout << code[i] << " ";
              cout << endl;
    }
}


void getAll() {
    cout << "Members who have participated in all events:\n";
    for (i = 0; i < s1; i++)
       for (j = 0; j < s2; j++)
          for (k = 0; k < s3; k++)
             for (m = 0; m < s4; m++) 
                if (code[i] == project[j] && project[j] == mastermind[k] && mastermind[k] == paper[m]) 
                    cout << code[i] << " ";
                    cout << endl;
      }
};

int main() {
    Student std;
    int choice;
    cout << "\n----EQUINOX----\n";
    std.getData(); 

    do {
        cout << "1.Students participated in coding and project competition:\n";
        cout << "2.Students participated in coding or project competition:\n";
        cout << "3.Students participated in coding but not in mastermind:\n";
        cout << "4.Students participated in all events:\n";
        cout << "5. Exit\n";
        cout << "Enter your choice:\n";
        cin >> choice;

        switch (choice) {
          case 1: std.second(); break;
          case 2: std.third(); break;
          case 3: std.fourth(); break;
          case 4: std.getAll(); break;
          case 5: cout << "Program Exited successfully!"; break;
          default: cout << "Invalid choice.\n"; break;
        }
    }  
    
    while (choice != 5);
    return 0;
}
