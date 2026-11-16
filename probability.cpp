/*
Name - Shravani More 
Practical 2 - (DSA) A drunken cockroach moves from title to tile with equal probability. How long will it take to touch at least once ?
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int row = 50;
const int col = 50;
int Tile[row][col];

void display_tiles(int x, int y) {
  int m = x; int n = y;
  cout << "\nTiles to walked are:\n\n";
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < n; k++) cout << "____";
    cout << endl;
    for (int j = 0; j < n; j++) cout "| " << i << j;
    cout << " | " << endl;
  }
  for (int k = 0; k < n; k++) cout << "____";
  cout << endl << endl;
}

int checker(int M, int N) {
   for (int i = 0; i < M; i++)
     for (int j = 0; j < N; j++) 
       if (Tile[i][j] == 0) return 1;
  return 0;
}


int main() {
  srand(time(0));
  int moves = 0, M, N, x, y;

  cout << "Enter the dimensions (M * N):\n";
  cin >> M >> N;
  cout << "Enter the initial positions (x, y):\n";
  cin >> x >> y;

  display_tiles(M, N)
    cout << endl << "( "<< x << " , " << y << ") ";

  int a = x, b = y;
  for (int i = 0; i < 50; i++)
     for (int j = 0; j < 50; j++) 
        Tile[i][j] == 0;

  Tile[x][y] == 1;

  while (checker(M, N)) {
    int r = rand() % 8;

    switch(r) {
      case 1: a++; break;
      case 2: b++; break;
      case 3: a--; break;
      case 4: b--; break;
      case 5: a++; b++; break;
      case 6: a++; b--; break;
      case 7: a--; b++; break;
      case 8: a--; b--; break;
    } 

    if (a >= 0 && a < M && b >= 0 && b < N) {
       cout << endl << "( "<< a << " , " << b << ") ";
      Tile[a][b]++;
    int x = a, y = b;
    moves++;
  } else {
    a = x, b = y;
    }
  }
  cout << "Total moves done are:\n" << moves << endl;
  return 0;
}
