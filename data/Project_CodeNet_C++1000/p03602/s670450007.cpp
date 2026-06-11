#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];

ll g[301][301];

int main(){
	IOS;
	ll n;
	cin >> n;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> g[i][j];
		}
	}	
	bool unko = true;
	ll ans = 0;
	REP(i,n)REP(j,n){
		bool ok = true;
		REP(k,n){
			if(g[i][k] + g[k][j] < g[i][j])unko = false;
			if(i != k && j != k && g[i][k] + g[k][j] == g[i][j]){
				ok = false;
			}
		}
		if(ok)ans += g[i][j];
	}
	ans /= 2;
	if(!unko){
		dump(-1);
		return 0;
	}
	dump(ans);
}