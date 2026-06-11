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
	
	const ll INF = 1e18;
	const ll mod = 1e9 + 7;

	//int dx[4] = {1,0,-1,0};
	//int dy[4] = {0,1,0,-1};
	//ll pas[51][52];
	ll n;
	vec<ll> g[114514];
	ll d[2][114514];
	ll used[2][114514] = {};
	void dfs(int d1,int d2,int sum){
		used[d1][d2] = true;
		for(int i = 0;i <g[d2].size();i++){
			if(!used[d1][g[d2][i]]){
				d[d1][g[d2][i]] = sum + 1;
				dfs(d1,g[d2][i],sum + 1);
			}
		}
	}

	signed main(){
		IOS;
		cin >> n;
		REP(i,n - 1){
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0,1,0);
		dfs(1,n,0);
		int fe = 0,su = 0;
		for(int i = 2;i < n;i++){
			if(d[0][i] <= d[1][i])fe++;
			else su++;
		}
		if(fe > su)dump("Fennec");
		else dump("Snuke");
	}