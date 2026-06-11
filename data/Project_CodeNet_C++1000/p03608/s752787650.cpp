#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[8]={ 1,0,-1,0,1,1,-1,-1 };
int dy[8]={ 0,1,0,-1,1,-1,1,-1 };

int N, M, R;
int r[8];
int cost[200][200];

signed main(){
	cin >> N >> M >> R;
	rep(i, R){
		cin >> r[i];
		r[i]--;
	}
	sort(r, r+R);
	rep(i, N){
		rep(j, N) cost[i][j] = 1e9;
		cost[i][i] = 0;
	}
	rep(i, M){
		int A, B, C;
		cin >> A >> B >> C;
		A--; B--;
		cost[A][B] = min(cost[A][B], C);
		cost[B][A] = min(cost[B][A], C);
	}

	rep(i, N){
		rep(j, N){
			rep(k, N){
				cost[j][k] = min(cost[j][k], cost[j][i]+cost[i][k]);
			}
		}
	}
	int ans = INT_MAX;
	do{
		int tmp = 0;
		rep(i, R-1){
			tmp += cost[r[i]][r[i+1]];
		}
		ans = min(ans, tmp);
	} while(next_permutation(r, r+R));
	cout << ans << endl;
}