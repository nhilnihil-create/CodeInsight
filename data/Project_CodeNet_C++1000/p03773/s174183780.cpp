#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int a, b;
	cin >> a >>b;
	a += b;
	if (a >= 24)a -= 24;
	cout << a << endl;
}