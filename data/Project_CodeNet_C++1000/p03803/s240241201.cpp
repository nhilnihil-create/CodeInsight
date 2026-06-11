#include <bits/stdc++.h>
using namespace std;

int A, B;

int main () {
	cin >> A >> B;
	if(A==1) A+=13;
	if(B==1) B+=13;
	if (A > B){
		cout << "Alice" << endl;
	}
	if (A < B){
		cout << "Bob" << endl;
	}
	if (A==B){
		cout << "Draw" << endl;
	}
}