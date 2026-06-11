#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

int N;
int x[100010];

int main() {
	cin >> N;
	rep(i, N) cin >> x[i];

	ll ret = 1;
	int num = 0;

	rep(i, N) {
		if (num * 2 + 1 <= x[i]) {
			++num;
		} else {
			ret = ret * (num + 1) % MOD;
		}
	}

	for (int i = 1; i <= num; ++i) {
		ret = ret * i % MOD;
	}

	cout << ret << endl;

	return 0;
}