#include <bits/stdc++.h>

using namespace std;

int main(){

	long long a, b, c;
	cin >> a >> b >> c;
	cout << min(abs(a / 2 * b*c - (a - a / 2)*b*c), min(abs(a*(b / 2)*c - a * (b - b / 2)*c), abs(a*b*(c / 2) - a * b*(c - c / 2)))) << endl;

	return 0;
}