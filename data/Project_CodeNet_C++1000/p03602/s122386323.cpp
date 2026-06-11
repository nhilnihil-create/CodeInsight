#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using IP = pair<int, int>;

const ll linf = 1LL << 62;
const int inf = 99999999;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const ll atcoder = 1e9 + 7;

#define Endl endl
#define mp make_pair
#define all(v) v.begin(),v.end()
#define pb push_back
#define pr(x) cout << x << endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define rep(i,n) for(int i= 0;i<n;i++)

template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

ll gcd(ll a, ll b) {//最大公約数
	if (a < b)swap(a, b);
	if (a%b == 0)return b;
	else gcd(b, a%b);
}

ll lcm(ll a, ll b) {//最小公倍数
	if (a < b)swap(a, b);
	return (a / gcd(a, b))*b;
}

int dist[310][310];
int a[310][310];

int main() {

	int n;
	cin >> n;

	rep(i, n) {
		rep(j, n) {
			cin >> a[i][j];
			dist[i][j] = a[i][j];
		}
	}

	rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	rep(i, n) {
		rep(j, n) {
			if (dist[i][j] < a[i][j]) {
				pr(-1);
				return 0;
			}
		}
	}

	ll sum = 0;

	rep(i, n) {
		for (int j = i + 1; j < n;j++) {
			bool flag = true;
			rep(k, n) {
				if (i != k && j != k) {
					if (dist[i][j] == dist[i][k] + dist[k][j]) {
						flag = false;
						break;
					}
				}
			}
			if (flag)sum += dist[i][j];
		}
	}
	
	pr(sum);

	//system("pause");
	return 0;
}