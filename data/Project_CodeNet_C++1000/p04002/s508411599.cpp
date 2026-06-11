#include"bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<< #str << " " str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7
constexpr ll SIZE = 1000000000;

ll H, W, N;
set<ll> candi, obj;

ll trans(ll y, ll x) {
	return y * SIZE + x;
}

pair<ll, ll> rev(ll pos) {
	return { pos / SIZE,pos%SIZE };
}

bool isin(pair<ll, ll> p) {
	return 0 <= p.first && p.first < H-2 && 0 <= p.second && p.second < W-2;
}

int main()
{
	cin >> H >> W >> N;
	REP(i, N) {
		ll a, b;
		cin >> a >> b;
		a--; b--;

		obj.insert(trans(a, b));
		REP(dy, 3)REP(dx, 3) if (isin({ a - dy,b - dx })) {
			candi.insert(trans(a - dy, b - dx));
		}
	}

	vector<ll> cnts(10);
	for (auto pos : candi) {
		int cnt = 0;
		REP(dx, 3)REP(dy, 3) {
			ll tmp = pos + dx * SIZE + dy;
			if (obj.find(tmp) != obj.end())cnt++;
		}
		cnts[cnt]++;
	}
	cnts[0] = (H - 2)*(W - 2) - accumulate(cnts.begin(), cnts.end(), 0);
	for (auto cnt : cnts) {
		cout << cnt << endl;
	}

	return 0;
}
