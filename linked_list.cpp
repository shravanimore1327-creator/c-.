/*
Name - Shravani More
Practical 6 - (DSA) Storing appointment schedule using linked lists
*/

#include <iostream>
#include <string>
using namespace std;

struct Appointment {
   int start, end;
   string name;
   Appointment* prev;
   Appointment* next;
};

class Schedule {
private: 
     Appointment* head;
     int toMinutes(int h, int m) {
         return h * 60 + m;
     }

void showTime(int t) {
     cout << (t / 60) << " : " << (t % 60 < 10 ? "0" : " " ) << t % 60;
    }

bool overlap(int s, int e) {
     for (Appointment* p = head; p; p = p->next) {
         if(!(e <= p->start || s >= p->end)) {
             return true;
         }
      if (p->start > e) {
            break;
        }
     } 
     return false;
   }

public:
    Schedule() : head(nullptr) { }

void bookAppointment() {
    int sh, sm, eh, em;
    string name;
    cout << "Enter the name:\n";
    cin >> name;
    cout << "Enter the start time (hh : mm)\n";
    cin >> sh >> sm;
    cout << "Enter the end time (hh : mm)\n";
    cin >> eh >> em;
    int s = toMinutes(sh, sm);
    int e = toMinutes(eh, em);
    if (s >= e || s < 540 || e > 1020) {
        cout << "Invalid Time. Working hours is 9:00 to 17:00\n";
        return;
    }
    if (e - s < 30) {
        cout << "Minimum slot is 30 Minutes!";
        return;
    }
    if (overlap(s, e)) {
        cout << "No free slots!";
        return;
    }
    Appointment* n = newAppointment{s, e, name, nullptr, nullptr};
    if (!head) {
        head = n;
        return;
    }
    Appointment* p = head; 
    while (p->next && p->next->start < s) {
        p = p->next;
    }

    n->next = p->next;
    if (p->next) {
        p->next->prev = n;
    }
    n->prev = p;
    p->next = n; 
    cout << "Appointment booked successfully!";
   } 


void displayAppointment() {
     if (!head) {
        cout << "No appointments scheduled!\n";
        return;
    }
    cout << "Display the Free Slots:\n";
    for (Appointment* p = head; p; p = p->next) {
         showTime(p->start);
              cout << " - ";        
         showTime(p->end)
              cout << " : " << p->name << "\n";
      }
   }


void freeSlots() {
    cout << "\nFree Slots:\n";
    if (!head) {
        cout << "Appointment 9:00 to 17:00\n";
        return;
     }
    int prevEnd = 540;
    for (Appointment* p = head; p; p = p->next) {
         if (p->start > prevEnd) {
           showTime(prevEnd);
           cout << " - ";
         showTime(p->start);
              cout << "\n";
       }
     prevEnd = p->end;
     if (prevEnd < 1020) {
         showTime(prevEnd);
            cout << " -17:00\n";
     }
   } 

void cancelAppointment() {
     int h, m;
     cout << "Enter the start time (hh : mm):\n";
     cin >> h >> m;
     int t = toMinutes(h, m);
     Appointment* p = head;
     while (p && p->start != t) {
          p = p->next;
     }
     if (!p) {
         cout << "Appointment not found!";
         return;
     } 
     if (p->prev) {
        p->prev->next = p->next;
     } else {
          head = p->next;
     }
    if (p->next) {
        p->next->prev = p->prev;
     } 
     delete p;
        cout << "Appointment cancelled successfully.\n";
   } 

void sortByData() {
     if (!head) return;
     for (Appointment* i = head; i && i->next; i = i->next) {
          for (Appointment* j = head; j && j->next; j = j->next) {
               if (j->start > j->next->start) {
                     swap(j->start, j->next->start);
                     swap(j->end, j->next->end);
                     swap(j->name, j->next->name);
               }
          }
     }
     cout << "Appointments are sorted by data.\n";
     displayAppointment();
  } 


void sortByPointer() {
     if (!head || head->next) {
     Appointment* sorted = nullptr;
     while (head) {
           Appointment* curr = head;
           head = head->next;
           curr->prev = curr->next = nullptr;
        }
     }
   }
};
