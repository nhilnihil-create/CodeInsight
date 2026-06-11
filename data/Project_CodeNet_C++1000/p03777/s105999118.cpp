#include <bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int A, B;
	if(a == "H"){
		A = 1;
    } else {
		A = 2;
    }
	if(b == "H"){
		B = 1;
    } else {
		B = 2;
    }
	A = A + B;
	if(A % 2 == 0){
		cout << "H";
    } else {
		cout << "D";
    }
}