#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M;
	cin >> N >> M;

	ll B[100001] = {};
	int mae;
	cin >> mae;
	int a1 = mae;
	int nanshuu = 0;
	ll kihon = 0;
	rep1(i, N - 1) {
		int a;
		cin >> a;
		int sa = a - mae;
		if (sa < 0) {
			sa += M;
			nanshuu++;
			kihon -= M - mae;
		}
		B[a] += sa;
		mae = a;
	}
	int aN = mae;
	kihon += (ll)nanshuu * M + aN - a1;

	ll saishou = kihon;
	rep1(x, M - 1) {
		int tmp = nanshuu;
		if (x > a1) tmp++;
		if (x > aN) tmp--;
		kihon += B[x] - tmp;
		chmin(saishou, kihon);
	}

	co(saishou);

	Would you please return 0;
}