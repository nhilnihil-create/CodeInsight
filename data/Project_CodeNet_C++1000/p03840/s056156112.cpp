#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
using mat = vector<vector<ll>>;

inline void IOS() { ios::sync_with_stdio(false), cin.tie(0); }

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[5001][5002];

signed main(){
	IOS();
	ll a[7];
	for (int i = 0;i < 7;++i) {
		cin >> a[i];
	}
	ll ans = (a[0] / 2) * 2 + a[1] + (a[3] / 2) * 2 + (a[4] / 2) * 2;
	if(a[0] % 2 + a[3] % 2 + a[4] % 2 == 3)ans += 3;
	else if(a[0] % 2 + a[3] % 2 == 2 && a[4] > 0){
		ans++;
	}
	else if(a[4] % 2 + a[3] % 2 == 2 && a[0] > 0){
		ans++;
	}
	else if(a[0] % 2 + a[4] % 2 == 2 && a[3] > 0){
		ans++;
	}
	cout << ans << endl;
}