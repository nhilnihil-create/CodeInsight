#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	int h, w; cin >> h >> w;
	int n; cin >> n;
	int a[10005];
	int b[10005];
	int c[105][105];
	rep(i, 0, n) cin >> a[i];
	int now = 0;
	rep(i, 0, n){
		rep(j, 0, a[i]){
			b[now+j] = i+1;
		}
		now += a[i];
	}
	now = 0;
	rep(i, 0, h){
		if(i%2==0){
			rep(j, 0, w){
				c[i][j] = b[now];
				now++;
			}
		}else{
			for(int j=w-1;j>=0;j--){
				c[i][j] = b[now];
				now++;
			}
		}
	}
	rep(i, 0, h){
		rep(j, 0, w){
			cout << c[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}