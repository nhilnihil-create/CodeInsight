#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll mp[333][333];

int main(){

	int n;cin>> n;
	REP(i,n)REP(j,n)cin >> mp[i][j];

	ll ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			bool flag = true;
			for(int k = 0;k < n;k++){
				if(k == i || k == j)continue;
				if(mp[i][j] > mp[i][k] + mp[k][j]){
					cout << -1 << endl;
					return 0;
				}
				if(mp[i][j] == mp[i][k] + mp[k][j])flag = false;
			}
			if(flag)ans += mp[i][j];
		}
	}

	cout << ans << endl;

	return 0;
}
