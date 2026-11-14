/*
Name - Shravani More 
Practical 10 - (DSA) Arrange the floating point numbers in the ascending orders using sorting techniques like selection sort, bubble sort, insertion sort, 
shell sort and also display the top five scores
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Sorting {
public: 

      void SelectionSort(float arr[], int n) {                  //SELECTION SORT
        for (int i = 0; i < n - 1; ++i) {
          int minIndex = i;
          for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
              minIndex = j;
            }
            swap (arr[i] , arr[minIndex]);
          }
        }
      }; 

      void BubbleSort(float arr[], int n) {                     //BUBBLE SORT
        for (int i = 0; i < n - 1; ++i) {          
          for (int j = i + 1; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1])
              swap (arr[j], arr[j + 1]); 
          }
        }
      };

      void InsertionSort(float arr[], int n) {                 //INSERTION SORT
        for (int i = 1; i < n ; ++i) {
          float key = arr[i];
          int j = i - 1;
          while (j >= 0 && arr[j] > key) {
          arr[j + 1] = arr[j];
          j--;
          }
          arr[j + 1] = key;
        }
      };

      void ShellSort(float arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            int i;
          float temp = arr[i];
          int j = i;
          while (j >= gap && arr[j - gap] > temp) {
            arr[j] = arr[j - gap];
            j -= gap;
          }
          arr[j] = temp;
        }
      }; 


      int partition(float arr[], int low, int high) {
        float pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) 
            if (arr[j] < pivot) 
              swap(arr[++i], arr[j]);
          swap(arr[i + 1], arr[high]);
          return i + 1;
        
      }
     

      void QuickSort(float arr[], int low, int high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1); 
        QuickSort(arr, pi + 1, high);
      }; 


      void display(float arr[], int n) {
        cout << "Top five scores:\n";
        for (int i = n - 1; i >= max(0, n - 5); --i) {
          cout << arr[i] << " ";
          cout << endl;
        }
      };
};



int main() {
 Sorting s; 
  int choice, n;
  cout << "Enter the number of students:\n";
  cin >> n;
  float arr[100];

  cout << "1.Manual Data.\n2.Random Data.\nEnter your choice:\n";
  cin >> choice;

  if (choice == 1) {
    cout << "Enter the percentages:\n";
    for (int i = 0; i < n; ++i)
    cin >> arr[i];
  } else {
    for (int i = 0; i < n; ++i) 
      arr[i] = rand() % 101;         //0 - 100 random percentages are choosen
  }
  

  cout << "\nMenu\n";
  cout << "1. Selection Sort.\n";
  cout << "2. Bubble Sort.\n";
  cout << "3. Insertion Sort.\n";
  cout << "4. Shell Sort.\n";
  cout << "5. Quick Sort.\n";
  cout << "6. STL Sort.\n";  
  cout << "Enter your choice:\n";
  cin >> choice;
  
  switch(choice) {
    case 1: s.SelectionSort(arr, n); break;
    case 2: s.BubbleSort(arr, n); break;
    case 3: s.InsertionSort(arr, n); break;
    case 4: s.ShellSort(arr, n); break;
    case 5: s.QuickSort(arr, 0, n - 1); break;
    case 6: sort(arr, arr + n); break;
    default: "Invalid Choice.\n";
    return 0;
  }
  cout << "\nSorted marks:\n";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";

  s.display(arr, n);
  return 0;
}
