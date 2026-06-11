#include <bits/stdc++.h>
using namespace std;

int main() {
  	int A, B, C;
  	cin >> A >> B;
    C = A+B;
  	if (A%3==0 || B%3==0 || C%3==0){
    	cout << "Possible" << endl;
    }
  	else {
    	cout << "Impossible" << endl;
    }
}