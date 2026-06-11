#include <bits/stdc++.h>

using namespace std;

int main() {

	long a, b, c;
	cin >> a >> b >> c;

	cout << (a!=b && a!=c && b!=c ? 3 : a==b && b!=c || a==c && a!=b || a!=b && b==c? 2
		 : 1) << endl;
}