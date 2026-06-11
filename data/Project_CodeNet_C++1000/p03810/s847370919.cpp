#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long inf = 1ll << 61;
int a[200006];
string res[] = { "Second","First" };
int gcd(int a, int b) {
	if (!b)return a; return gcd(b, a%b);
}
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> a[i];
	if (n % 2) {
		int e = 0;
		rep(i, n)if (!(a[i] & 1))e++;
		if (e & 1)cout << res[e & 1] << endl;
		else {
			int cnt = 0;
			while (n - e == 1) {
				int C;
				rep(i, n) {
					if (a[i] & 1) {
						C = a[i]; a[i]--;
					}
				}

				if (C == 1) {
					cout << res[(e + cnt) & 1] << endl; return 0;
				}

				int g = a[0];
				rep(i, n)g = gcd(g, a[i]);
				rep(i, n)a[i] /= g;
				e = 0;
				rep(i, n)if (!(a[i] & 1))e++;
				cnt++;
			}
			cout << res[(e+cnt) & 1]<<endl;
		}
	}
	else {
		int s = 0;
		rep(i, n)s += a[i];
		cout << res[s & 1] << endl;
	}
}