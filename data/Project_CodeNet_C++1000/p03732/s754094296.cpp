#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int main(){
	ll n, W;
	scanf("%lld %lld", &n, &W);
	vector<ll> w(n), v(n);
	scanf("%lld %lld", &w[0], &v[0]);
	vector<vector<ll> > a(4);
	a[0].push_back(v[0]);
	for(int i = 1; i < n; i++){
		scanf("%lld %lld", &w[i], &v[i]);
		a[w[i] - w[0]].push_back(v[i]);
	}
	for(int i = 0; i < 4; i++){
		sort(a[i].begin(), a[i].end(), greater<ll>());
		for(int j = 0; j < a[i].size(); j++){
			if(j == 0) continue;
			a[i][j] += a[i][j - 1];
		}
	}
	ll ans = 0;
	for(int x0 = 0; x0 <= a[0].size(); x0++){
		for(int x1 = 0; x1 <= a[1].size(); x1++){
			for(int x2 = 0; x2 <= a[2].size(); x2++){
				for(int x3 = 0; x3 <= a[3].size(); x3++){
					if(x0 + x1 + x2 + x3 > n) continue;
					if(w[0] * x0 + (w[0] + 1) * x1 + (w[0] + 2) * x2 + (w[0] + 3) * x3 > W) continue;
					ll ans1 = 0;
					if(a[0].size() && x0) ans1 += a[0][x0 - 1];
					if(a[1].size() && x1) ans1 += a[1][x1 - 1];
					if(a[2].size() && x2) ans1 += a[2][x2 - 1];
					if(a[3].size() && x3) ans1 += a[3][x3 - 1];
					ans = max(ans, ans1);
				}
			}
		}
	}
	cout << ans << endl;
}