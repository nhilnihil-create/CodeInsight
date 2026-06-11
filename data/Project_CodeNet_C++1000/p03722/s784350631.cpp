#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef int64_t lint;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;

struct edge {
	int from; //出発点
	int to;   //到達点
	lint cost; //移動コスト
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<edge> v(M);
	rep(i, M) {
		cin >> v.at(i).from >> v.at(i).to >> v.at(i).cost;
		v.at(i).from--, v.at(i).to--;
	}

	vector<lint> d(N);
	fill(all(d), -LINF);
	d.at(0) = 0;

	int x, y, z;
	bool f;
	rep(i, N) {
		rep(j, M) {
			x = v.at(j).from;
			y = v.at(j).to;
			z = v.at(j).cost;
			f = chmax(d.at(y), d.at(x) + z);
			if (f && i == N-1 && y == N-1) {
				cout << "inf" << '\n';
				return 0;
			}
		}
	}
	cout << d.at(N-1) << '\n';
}
