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
	
	ll powm(ll a, ll b, ll c) {
		if (b == 0)return 1;
		else if (b % 2 == 0) {
			ll d = powm(a, b / 2, c);
			return (d * d) % c;
		}
		else return (a * powm(a, b - 1, c)) % c;
	}

	signed main(){
		IOS;
		ll n, t;
		cin >> n >> t;
		vec<ll> a(n);
		REP(i,n)cin >> a[i];
		map<ll,ll> mp;//最大の差とその個数
		ll d = a[0],u = a[0];
		REP(i,n){
			if(d > a[i])d = a[i];
			mp[d - a[i]]++;
		}
		ll kosuu = mp.begin()->second;
		dump(kosuu);
	}