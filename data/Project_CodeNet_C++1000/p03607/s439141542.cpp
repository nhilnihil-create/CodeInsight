#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n,i,c=0;
	cin >> n;
	vector<long long> v(n);
	map<long long, int> m;

	rep(i, n) {
		cin >> v[i];
		m[v[i]]++;
	}
	rep(i, n) {
		if (m[v[i]] % 2 == 1)c++;
		m[v[i]] = 0;
	}
	cout << c << endl;
	return 0;
}