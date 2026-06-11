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
		ll h, w, a, b;
		cin >> h >> w >> a >> b;
		vec<ll> x(h + w + 1), y(h + w + 1);
		x[0] = y[0] = 1;
		for(ll i = 1;i <= h + w;i++){
			x[i] = (x[i - 1] * i) % mod;
			y[i] = (y[i - 1] * powm(i,mod - 2,mod)) % mod;
		}
		ll ans = (x[h + w - 2] * y[h - 1]) % mod;
		ans = (ans * y[w - 1]) % mod;
		ll sum = 0;	
		for(int i = 0;i <= b - 1;i++){
			ll tmp = (((x[h - a + i - 1] * y[h - a - 1]) % mod ) * y[i]) % mod;
			tmp = (((((tmp * x[w + a - i - 2]) % mod) * y[a - 1]) % mod) * y[w - i - 1]) % mod;
			sum = (sum + tmp) % mod;  
		}
		while(ans < sum){
			ans += mod;
		}
		dump(ans - sum);
	}