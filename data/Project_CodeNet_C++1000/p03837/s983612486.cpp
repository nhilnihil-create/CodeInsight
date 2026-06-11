#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N, M;
vector<tuple<int, int, int>> v;
int cost[100][100];

signed main(){
	cin >> N >> M;
	rep(i, N){
		rep(j, N){
			cost[i][j] = 1e9L;
		}
	}
	rep(i, N){
		cost[i][i] = 0;
	}

	rep(i, M){
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		v.pb({ c,a,b });
		cost[a][b] = c;
		cost[b][a] = c;
	}
	rep(i, N){
		rep(j, N){
			rep(k, N){
				cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
			}
		}
	}
	sort(all(v));

	int ans = 0;
	rep(i, v.size()){
		int a = get<1>(v[i]);
		int b = get<2>(v[i]);
		int c = get<0>(v[i]);
		if(cost[a][b] != c) ans++;
	}
	cout << ans << endl;
}