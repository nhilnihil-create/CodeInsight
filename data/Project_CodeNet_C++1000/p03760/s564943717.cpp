#include <bits/stdc++.h>
using namespace std;

string E, O;

int main () {
	cin >> O >> E;
	for (int i = 0; i < O.length()+E.length(); i++){
		if (i%2 == 0){
			cout << O[i/2];
		} else {
			cout << E[i/2];
		}
	}
}