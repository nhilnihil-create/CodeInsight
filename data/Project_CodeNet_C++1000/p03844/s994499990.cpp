/*A - Addition and Subtraction Easy*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long num1;
	long long num2;
	string signo;

	cin >> num1 >> signo >> num2;

	if(signo == "+")
		cout << num1 + num2;
	else
		cout << num1 - num2;

	return 0;
}