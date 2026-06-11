#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <iomanip>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <cmath>

#include <set>

#include <map>

#include <string>

#include <numeric>

#include <cstdio>

#include <cstdlib>

using namespace std;


const int INF = 10000000;

typedef pair<int, int> P;
typedef long long ll;
#define PB push_back

//char maze[100][101];

ll n, m;

int sx, sy;

int gx, gy;

int qqq;

//各座標までの最短距離

int d[100][100];


//移動方向のベクトル

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int ans = 0;
pair<int, int> red[101], blue[101];
//ll a[200000], b[20000];

//ユークリッドの互除法
ll gcd(ll x, ll y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x%y);
}

//エラトステネスの篩 prime(n)[k]で1~nまで探索して(k+1)番目の素数を出力
vector<int> prime(int n) {
	vector<int> erst;
	for (int i = 0; i < n; ++i) erst.PB(i);
	erst[0] = erst[1] = NULL;
	auto dmax = sqrt(n);

	for (int dx = 2; dx < dmax; ++dx) {
		if (erst[dx] == NULL) continue;
		for (int i = dx * 2; i < n; i += dx) erst[i] = NULL;
	}

	vector<int> erstlist;
	for (auto i : erst) if (i) erstlist.PB(i);

	return erstlist;
}

ll v_find(std::vector<ll> vec, ll number) {
	auto itr = std::find(vec.begin(), vec.end(), number);
	size_t index = std::distance(vec.begin(), itr);
	if (index != vec.size()) { // 発見できたとき
		return 1;
	}
	else { // 発見できなかったとき
		return 0;
	}
}

ll BIG = 10000000000;

ll POW(ll a, ll b) {
	if (b == 0) return 1;
	return (a*POW(a, b - 1)) % BIG;
}

int Kaijou(int a) {
	if (a < 2) return 1;
	return a * Kaijou(a - 1);
}


ll aa[51];

int main() {
	/*int n,k;
	cin >> n >> k;
	int a[5000] = { 0 };
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int sum = 0;
	int i;
	for (i = n - 1; i >= 0; --i) {
		sum += a[i];
		if(sum)
	}
	cout << pp << endl;*/
	int x;
	cin >> x;
	int t = 1;
	int sum = 0;
	while (1) {
		sum += t;
		if (sum >= x) {
			cout << t << endl;
			return 0;
		}
		t++;
	}
	return 0;
}