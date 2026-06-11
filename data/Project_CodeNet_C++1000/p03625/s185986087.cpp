#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//for(auto p:mp)(mapの探索)
//printf("%.10f\n",なんちゃら)

int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//素因数分解
vector<pair<ll, int>>factorize(ll n) {
	vector<pair<ll, int>>res;
	for (ll i = 2;i * i <= n;++i) {
		if (n % i)continue;
		res.emplace_back(i, 0);
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1)res.emplace_back(n, 1);
	return res;
}

int bingo[3][3];
bool flag[3][3];
int cnt[2][105];
int h, w;
int choco[1010][1010];
int s[11][11];

int main() {
	int n;
	cin >> n;
	vector<ll>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	int res = 0;
	ll ans = 1;
	for (int i = 1;i < n;++i) {
		if (a[i - 1] == a[i]) {
			ans *= a[i];
			i++;
			res++;
			if (res == 2)break;
		}
	}
	if (res == 2)cout << ans << endl;
	else cout << 0 << endl;
	return 0;
}
