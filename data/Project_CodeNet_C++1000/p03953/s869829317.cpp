#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 1e9+7;


ll to[65][100005];
ll pos[65][100005];
int main(){
	ios_base::sync_with_stdio(false);
	ll N, M, K;
	ll x[100005], a[100005];

	cin >> N;
	rep(i,N) cin >> x[i];
	cin >> M >> K;
	rep(i,M){
		cin >> a[i];
		a[i]--;
	}

	rep(i,N-1) to[0][i] = i;
	rep(i,M) swap(to[0][a[i]-1], to[0][a[i]]);
	rep(k,63) rep(i,N-1) to[k+1][i] = to[k][ to[k][i] ];
	
	rep(i,N-1) pos[0][i] = i;
	rep(k,63){
		if( (1ll<<k) & K ){
			rep(i,N-1) pos[k+1][i] = pos[k][ to[k][i] ];
		}else{
			rep(i,N-1) pos[k+1][i] = pos[k][i];
		}
	}

	cout << x[0] << endl;
	ll cur = x[0];
	rep(i,N-1){
		int n = pos[63][i];
		cur += x[n+1] - x[n];
		cout << cur << endl;
	}

	return 0;
}
