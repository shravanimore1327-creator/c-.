/*
Name - Shravani More
Practical 9 - (DSA) Orders of pizza parlour are taken on FCFS basis and once order placed cannot be canceled, write a menu driven program 
using simple or circular queue.
*/

#include <iostream>
#include <queue>
using namespace std;

const int MAX_ORDERS = 10;
queue<int> orderQueue;                                                                                                           /*

void display() {
  cout << "\nPizza Parlour Menu.\n";
  cout << "1. Place the order.\n";
  cout << "2. Serve the next order.\n";
  cout << "3. Display the current orders.\n";
  cout << "4. Exit.\n";
  cout << "Enter your choice:\n";
 
}
                                            
int main() {
  int choice; 

do {
 display(); 
      cin >> choice;
      switch(choice) {
        
           case 1: 
        if (orderQueue.size() >=  MAX_ORDERS) {
          cout << "Sorry the orders are full right now!\n";
        } else {
          int orderNum;
          cout << "Enter the order number:\n";
          cin >> orderNum;
          orderQueue.push(orderNum);
          cout << "Order placed successfully.\n"; 
          cout << "Total accepted orders: " << orderQueue.size() << endl;
        }
      break;

        case 2:
         if (orderQueue.empty()) {
        cout << "No orders has been served.\n";
      } else {
        int orderServed;
        orderServed = orderQueue.front();
        orderQueue.pop();
        cout << "Order " << orderServed << " has been served.\n";
      }
    break;

        case 3:
        if (orderQueue.empty()) {
        cout << "No current orders.\n";
        } else {
        cout << "Curr
          ent orders.\n";
        queue<int> tempQueue = orderQueue;
        while (!tempQueue.empty()) {
           cout << tempQueue.front() << " ";
           tempQueue.pop();
          cout << "\nTotal pending orders: " << orderQueue.size() << endl;
        }
      }
       break; 

        case 4: 
        cout << "Exited.";
        break; 

        default :
        cout << "Invalid choice! Please try again.\n";
       }  
   }  while (choice != 4);
      return 0;  
}
