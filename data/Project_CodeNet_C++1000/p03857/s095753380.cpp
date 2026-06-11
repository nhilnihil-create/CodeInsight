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
	struct UnionFind {
		vector<int> data;
		UnionFind(int size) : data(size, -1) {}
		void unionSet(int x, int y) {
			x = root(x), y = root(y);
			if (x != y) {
				if (data[y] < data[x])swap(x, y);
				data[x] += data[y]; data[y] = x;
			}
		}
		bool findSet(int x, int y) {
			return root(x) == root(y);
		}
		int root(int x) {
			return data[x] < 0 ? x : data[x] = root(data[x]);
		}
		int size(int x) {
			return -data[root(x)];
		}
	};

	signed main(){
		IOS;
		ll n, k, l;
		cin >> n >> k >> l;
		UnionFind ufa(n + 1), ufb(n + 1);
		REP(i, k){
			int x, y;
			cin >> x >> y;
			ufa.unionSet(x, y);
		}
		REP(i, l){
			int x ,y;
			cin >> x >> y;
			ufb.unionSet(x, y);
		}
		map<P,ll> mp;
		for(int i = 1;i <= n;i++){
			mp[P(ufa.root(i),ufb.root(i))]++;
		}
		for(int i = 1;i <= n;i++){
			if(i != 1)cout << " ";
			cout << mp[P(ufa.root(i),ufb.root(i))];
		}
		cout << endl;
	}