/*
Practical 12 - (DSA) maintains list of data representing temperature, humidity, pollution level using maxmin, highlow, average,
*/

#include<iostream> 
#include<algorithm> 
#include<climits> 
using namespace std; 

class environment { 
public:    
    int n, avgt = 0, avgh = 0, avgp = 0;    
    int temperature[50];    
    int humidity[50];    
    int pollution[50];    
    int max_temp = 0, max_humid = 0, max_poll = 0;    
    int min_temp = INT_MAX, min_humid = INT_MAX, min_poll = INT_MAX; 

public:    
    void getdata();    
    void display();    
    void average();    
    void maxmin();    
    void highlow();    
    void sortData();    
    void impactAnalysis(); 
}; 


void environment::getdata() {    
     cout << "Enter the number of entries: ";    
     cin >> n;    
     for (int i = 1; i <= n; i++) {        
         cout << "Enter the Temperature for " << i << ": ";        
         cin >> temperature[i];        
         cout << "Enter the Humidity for " << i << ": ";        
         cin >> humidity[i];        
         cout << "Enter the Pollution Level for " << i << ": ";        
         cin >> pollution[i];        
         cout << endl;    
     } 
} 


void environment::display() {    
     cout << "-----DISPLAYING DATA-----------" << endl;    
     cout << "Srno\tTemperature\tHumidity\tPollution Level" << endl;    
     for (int i = 1; i <= n; i++) {        
          cout << i;        
          cout << "\t" << temperature[i];        
          cout << "\t\t" << humidity[i];        
          cout << "\t\t" << pollution[i];        
           cout << endl;    
     } 
}


void environment::average() {    
     cout << "----------AVERAGE OF EACH PARAMETERS----------" << endl;    
     for (int i = 1; i <= n; i++) {        
         avgt += temperature[i];        
         avgh += humidity[i];        
         avgp += pollution[i];    
     }    
     cout << "Average of Temperature: " << float(avgt / n) << endl;    
     cout << "Average of Humidity: " << float(avgh / n) << endl;    
     cout << "Average of Pollution Level: " << float(avgp / n) << endl; 
} 


void environment::maxmin() {    
     for (int i = 1; i <= n; i++) {        
         max_temp = max(max_temp, temperature[i]);        
         min_temp = min(min_temp, temperature[i]);        
         max_humid = max(max_humid, humidity[i]);        
         min_humid = min(min_humid, humidity[i]);        
         max_poll = max(max_poll, pollution[i]);        
         min_poll = min(min_poll, pollution[i]);    
     }    
     cout << "---------Maximum of Each Parameters----------" << endl;    
     cout << "Maximum of temperature: " << max_temp << endl;    
     cout << "Minimum of temperature: " << min_temp << endl;    
     cout << "Maximum of Humidity: " << max_humid << endl;    
     cout << "Minimum of Humidity: " << min_humid << endl;    
     cout << "Maximum of Pollution: " << max_poll << endl;    
     cout << "Minimum of Pollution: " << min_poll << endl; 
} 


void environment::highlow() {    
     if (max_temp > 45) {        
         cout << "NOT SAFE TEMPERATURE" << endl;    
     } else {        
         cout << "SAFE TEMPERATURE" << endl;    
     }    
     if (max_humid > 40) {        
         cout << "HIGH HUMIDITY" << endl;    
     } else {        
         cout << "NORMAL HUMIDITY" << endl;    
     }    
     if (max_poll > 300) {        
         cout << "HIGH POLLUTION LEVEL" << endl;    
     } else {        
         cout << "NORMAL POLLUTION LEVEL" << endl;    
     } 
} 


void environment::sortData() {    
     sort(temperature + 1, temperature + n + 1);    
     cout << "-----DISPLAYING SORTED DATA-----------" << endl;    
     cout << "Srno\tTemperature\tHumidity\tPollution Level" << endl;    
     for (int i = 1; i <= n; i++) {        
          cout << i;        
          cout << "\t" << temperature[i];        
          cout << "\t\t" << humidity[i];        
          cout << "\t\t" << pollution[i];        
          cout << endl;    
     } 
} 


void environment::impactAnalysis() {    
     if (max_temp > 35 && max_humid > 30) {        
          cout << "High temperature and humidity can lead to discomfort.\n";    
     }    
     if (max_poll > 200) {        
          cout << "High pollution levels may have adverse effects on health.\n";    
     }    cout << "Impact analysis completed.\n"; 
} 


int main() {    
   environment e;    
   int choice;    
   do {        
     cout << "\nMenu:\n";        
     cout << "1. Enter Data\n";        
     cout << "2. Display Data\n";        
     cout << "3. Calculate Average\n";        
     cout << "4. Find Max and Min\n";        
     cout << "5. Check High and Low Parameters\n";        
     cout << "6. Sort Data\n";        
     cout << "7. Perform Impact Analysis\n";        
     cout << "8. Exit\n";        
     cout << "Enter your choice: ";        
     cin >> choice;        
     
     switch (choice) {            
       case 1: e.getdata(); break;            
       case 2: e.display(); break;            
       case 3: e.average(); break;            
       case 4: e.maxmin(); break;            
       case 5: e.highlow(); break;            
       case 6: e.sortData(); break;            
       case 7: e.impactAnalysis(); break;            
       case 8: cout << "Exiting program.\n"; break;            
       default: 
         cout << "Invalid choice. Please enter a valid option.\n";        
     }    
   } 
     while (choice != 8);    
    return 0; 
}
