#include<bits/stdc++.h>
using namespace std;
#define ll long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s;
	int a, b;
	cin >> a >> s >> b;
	if (s == "+") {
		cout << a + b << endl;
	} else {
		cout << a - b << endl;
	}
}