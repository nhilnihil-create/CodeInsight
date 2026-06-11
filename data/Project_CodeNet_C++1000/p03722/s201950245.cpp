#include<bits/stdc++.h>
#define int long long
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
#define all(x) x.begin(),x.end()
#define puts(x) cout << x << "\n"
constexpr int mod = 1000000007;
using namespace std;
int input() { int r; cin >> r; return r; }
int n, m;
int a[2345], b[2345], c[2345], p[1234];
bool b00l[1234];
signed main() {
	cin >> n >> m;
	for1(i, m)cin >> a[i] >> b[i] >> c[i];
	b00l[1] = 1;
	for1(valsqotch, 3 * n + 10) {
		for1(i, m) {
			if (b00l[a[i]]) {
				if (!b00l[b[i]]) {
					b00l[b[i]] = 1;
					p[b[i]] = p[a[i]] + c[i];
				}
				else {
					if (p[b[i]] < p[a[i]] + c[i]) {
						if (b[i] == n && valsqotch > 2 * n) {
							puts("inf"); return 0;
						}
						p[b[i]] = p[a[i]] + c[i];
					}
				}
			}
		}
	}
	puts(p[n]);
}