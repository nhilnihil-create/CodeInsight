#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	ll a[n][n];
	rep(i,n) rep(j,n) cin >> a[i][j];


	// Warshall-Floyd

	// すべての2頂点間に辺を張ったグラフを考え、各距離がa[i][j]であるとする
	// 最短距離の更新があれば、そのようなグラフは存在しない(最短距離の情報が矛盾している)	
    // a[i][j] == a[i][k] + a[k][j]　であれば、辺ijは不要

	bool b[n][n] = {};

	ll sum = 0;
	FOR(i,0,n){
		FOR(j,i+1,n){
			sum += a[i][j];
		}
	}

	ll ans = 0;

	rep(k,n){
		rep(i,n){
			rep(j,n){
				if(k != i && i != j && j!= k) {
					if(a[i][j] > a[i][k] + a[k][j]){
						cout << -1 << endl;
						return 0;
					}else{
						if((a[i][j] == a[i][k] + a[k][j]) && (!b[i][j] || !b[j][i])){
							ans += a[i][j];
							b[i][j] = true;
							b[j][i] = true;
						}
					}
				}
			}
		}
	}
	
	cout << (sum - ans) << endl;
}