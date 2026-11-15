/*
Name - Shraani More
Practical - 5 (DSA) Polynomial read, display, addition, finding transpose using simple and fast transpose methods.
*/

#include <iostream>
using namespace std;


struct Poly {
	int coeff, exp;
};


int main() {
	Poly p1[10], p2[10], p3[20];
	int n, m, i = 0, j = 0, k = 0;


	cout << "Enter the terms of first polynomial:\n";
	cin >> n;
	for (int a = 0; a < n; a++) {
	    cin >> p1[a].coeff >> p1[a].exp;
	}


	cout << "Enter the terms of second polynomial:\n";
	cin >> m;
	for (int a = 0; a < m; a++) {
	    cin >> p2[a].coeff >> p2[a].exp;
	} 


	while (i < n && j < m) {
	    if (p1[i].exp > p2[j].exp) 
           p3[k++] = p1[i++];

        else if (p1[i].exp < p2[j].exp) 
           p3[k++] = p2[j++];

        else {
           p3[k].coeff = p1[i].coeff + p2[j].coeff;
           p3[k++].exp = p1[i++].exp;
           i++;
           j++;
        }
	}

	while (j < n) p3[k++] = p1[i++];
	while (j < m) p3[k++] = p2[j++];
	cout << "Result:\n"; 
	for (int a = 0; a < k; a++) {
	    cout << p3[a].coeff << "x^" << p3[a].exp << " + ";
	}
	return 0;
}
