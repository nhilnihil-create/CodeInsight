#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int m[105][105];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int w,h,n;
	cin >> w >> h >> n;
	
	FOR(i,0,n){
		int x, y, a;
		cin >> x >> y >> a;
		FOR(i,0,w) {
			FOR(j,0,h) {
				if (a == 1 && i < x) {
					m[i][j]=1;
				}
				if (a == 2 && i >= x) {
					m[i][j]=1;
				}
				if (a == 3 && j < y) {
					m[i][j]=1;
				}
				if (a == 4 && j >= y) {
					m[i][j]=1;
				}
			}
		}
	}
	int t = 0;
	FOR(i,0,w) {
		FOR(j,0,h) {
			t+=m[i][j]==0;
		}
	}
	cout << t << "\n";

}
