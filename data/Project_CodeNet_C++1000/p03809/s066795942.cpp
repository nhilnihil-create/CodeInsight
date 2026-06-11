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


vector<int> edge[100005];
ll A[100005];

ll dfs(int n, int b){
	if( edge[n].size() == 1 ){
		return A[n];
	}
	ll mx = 0, sum = 0;
	for(auto t: edge[n]) if( t != b ){
		auto r = dfs(t, n);
		if( r < 0 ) return -1;
		chmax(mx, r);
		sum += r;
	}
	if( A[n] < mx ) return -1;
	if( A[n]*2ll < sum ) return -1;
	if( A[n] > sum ) return -1;
	ll ret = A[n]*2ll - sum;
	//cout << "dfs: " << n << " "  << ret << endl;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int N;

	cin >> N;
	rep(i,N) cin >> A[i];
	rep(i,N-1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	bool ans;
	rep(i,N) if( edge[i].size() > 1 ){
		auto ret = dfs(i, -1);
		ans = (ret == 0);
		break;
	}

	if( N == 2 ){
		ans = (A[0] == A[1]);
	}

	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}