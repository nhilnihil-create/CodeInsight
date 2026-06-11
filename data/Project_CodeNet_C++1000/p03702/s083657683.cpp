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
	ll n, a, b;
	ll h[114514];
	bool ok(ll x){
		ll sum = b * x;
		ll cnt = 0;
		REP(i,n){
			cnt += max(0ll,(h[i] - sum  + a - b - 1) / (a - b));
		}
		if(cnt <= x)return true;
		else return false;
	}

	signed main(){
		IOS;
		cin >> n >> a >> b;
		REP(i,n)cin >> h[i];
		ll left = 0;
		ll right = mod;
		ll mid;
		while(1 < right - left){
			mid = (right + left) / 2;
			if(ok(mid))right = mid;
			else left = mid;
		}
		dump(right);
	}