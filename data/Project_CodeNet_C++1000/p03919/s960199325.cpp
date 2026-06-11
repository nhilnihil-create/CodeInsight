#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define v(n) int n; cin>>n;
using namespace std;

int main() {
	v(h); v(w);
	string o;
	char a = 'A';
	rep(i, h) {
		rep(j, w) {
			cin >> o;
			if (o == "snuke") {
				a += j;
				cout << a << i + 1 << endl;
			}
		}
	}
}
