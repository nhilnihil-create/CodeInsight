#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int h,w; cin >> h >> w;
	char c[h][w];
	rep(i,h)rep(j,w) cin >> c[i][j];
	rep(i,h) {
		rep(j,w) {
			cout << c[i][j];
		}
		cout << endl;
		rep(j,w) {
			cout << c[i][j];
		}
		cout << endl;
	}
}