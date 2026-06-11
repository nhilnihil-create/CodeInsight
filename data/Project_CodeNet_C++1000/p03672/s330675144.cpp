#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	int n = s.length() - 1;
	if (n % 2) n--;
	while (s.substr(0, n / 2).compare(s.substr(n / 2, n / 2)) != 0) n -= 2;
	cout << n;
}