/*
Name - Shravani More
Roll No - 37
Practical 11 C++ DS
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

class HashTable {
	int SIZE;
	list<pair<int, string>>* table; 

	int hashFunction(int key) {
	    return key % SIZE;
	  }; 

public:
    HashTable(int size) {
	SIZE = size;
	table = new list<pair<int, string>>[SIZE];
	}


void insert(int key, string value) {
	int index = hashFunction(key);
	for (auto &p: table[index]) {
	     if (p.first == key) {
	         p.second = value;
	         cout << "Updated " << " ( " << key << " : " << value << " ) \n ";
	         return;
	     }
	}
	table[index].push_back({key, value});
	cout << "Inserted " << " ( " << key << " : " << value << " ) \n ";
};


void find(int key) {
	int index = hashFunction(key);  
	for (auto &p: table[index]) {
	     if (p.first == key) {	         
	        cout << "Found " << " ( " << key << " : " << p.second << " ) \n ";
	        return;
	     }
	}
	cout << "Key not found!";
};


void remove(int key) {
	int index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
	     if (it->first == key) {
	         table[index].erase(it);	         
	         cout << "Deleted " << key << endl;
	         return;
	    }
	}
	cout << "Key not found!";
};


void display() {
	cout << "\n----Hash Table----\n";
	for (int i = 0; i < SIZE; i++) { 
	    cout << "Bucket " << i << " : ";
	    for (auto &p: table[i]) {
	        cout << "Display " << "( " << p.first << " : " << p.second << " ) \n";
	        cout << endl;
		    }
	    }    
	}
}; 


int main() {

    int size;
    cout << "Enter the HashTable:\n";
    cin >> size;

    HashTable dict(size);
	int choice, key;
	string value;
    
	do {
	    cout << "\nMenu\n";
	    cout << "1. Insert HashTable\n";
	    cout << "2. Find HashTable\n";
	    cout << "3. Delete HashTable\n";
	    cout << "4. Display HashTable\n";
	    cout << "Exiting Program\n";
	    cout << "Enter your choice: \n";
	    cin >> choice;

	switch(choice) {
	    case 1: 
        cout << "Enter the key and values to insert: ";
        cin >> key >> value;
        dict.insert(key, value);
        break;

        case 2: 
        cout << "Enter the key to find: ";
        cin >> key;
        dict.find(key);
        break; 

        case 3: 
        cout << "Enter the key to remove: ";
        cin >> key;
        dict.remove(key);
        break;

        case 4:        
        dict.display();         //Displaying the Data in HashTable
        break;

	    }
	} while(choice != 5);
	return 0;	
}
