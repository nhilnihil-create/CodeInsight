#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define v(n) int n; cin>>n;
using namespace std;

int main() {
	string o, p = "CODEFESTIVAL2016";
	cin >> o;
	int x = 0;
	rep(i, 16) {
		if (o[i] != p[i]) x++;
	}
	cout << x << endl;
}