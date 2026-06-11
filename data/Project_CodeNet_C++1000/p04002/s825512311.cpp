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
		ll h,w,n;
		cin >> h >> w >> n;
		map<P,ll> mp;
		REP(i,n){
			ll x, y;
			cin >> y >> x;
			for(int dx = -1;dx <= 1;dx++){
				for(int dy = -1;dy <= 1;dy++){
					int nx = x + dx, ny = y + dy;
					if(nx >= 2 && nx <= w - 1 && ny >= 2 && ny <= h - 1) //中央のマスはx:2~w-1かつy:2~h-1
						mp[P(nx,ny)]++;
				}
			}
		}
		vec<ll> cnt(10,0);
		ll sum = 0;
		for(auto it = mp.begin();it != mp.end();it++){
			cnt[it->second]++;
			sum++;
		}
		cnt[0] = (h - 2) * (w - 2) - sum;
		REP(i,10){
			dump(cnt[i]);
		}
	}