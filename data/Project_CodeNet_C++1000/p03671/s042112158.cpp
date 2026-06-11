#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	cout << a + b + c - max(max(a, b), c);
}