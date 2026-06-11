#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin >> A >> B;
	if(A%3 && B%3 && (A+B)%3)
		cout << "Impossible";
	else
		cout << "Possible";
	cout << endl;
}