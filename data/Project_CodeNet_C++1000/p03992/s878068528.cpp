#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define v(n) int n; cin>>n;
using namespace std;

int main() {
	vector<char> o(4);
	string p;
	rep(i, 4) {
		cin >> o[i];
		cout << o[i];
	}
	cout << ' ';
	cin >> p;
	cout << p << endl;
}