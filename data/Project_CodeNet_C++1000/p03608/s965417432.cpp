// MTGSさんのｼｬｷｮｳ
#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

const ll inf = 1e10;
int main()
{
	ll N, M, R, ans = inf;

	cin >> N >> M >> R;
	vector<ll> r(R);
	rep(i, R){
		cin>>r[i];
		r[i]--;
	}
	SORT(r);
	vector<vector<ll>> d(N,vector<ll>(N,inf));
	rep(i,N) d[i][i] = 0;
	rep(i,M){
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		d[a][b] = c;
		d[b][a] = c;
	}

	rep(k,N)rep(i,N)rep(j,N){
		d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	}
	do {
		ll now = 0;
		rep(i,R-1){
			now += d[r[i]][r[i+1]];
		}
		ans = min(ans,now);
	} while (next_permutation(r.begin(),r.end()));
	cout << ans << endl;
}
