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
int a[1000], b[1000], c[1000];
int cost[100][100];

signed main(){
	scanf("%d%d", &N, &M);
	rep(i, N){
		rep(j, N){
			cost[i][j] = 1'000'000'000;
		}
	}
	rep(i, N){
		cost[i][i] = 0;
	}

	rep(i, M){
		scanf("%d%d%d", a+i, b+i, c+i);
		a[i]--; b[i]--;
		cost[a[i]][b[i]] = c[i];
		cost[b[i]][a[i]] = c[i];
	}
	rep(i, N){
		rep(j, N){
			rep(k, N){
				cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
			}
		}
	}

	int ans = 0;
	rep(i, M){
		if(cost[a[i]][b[i]] != c[i]) ans++;
	}
	printf("%d\n", ans);
}