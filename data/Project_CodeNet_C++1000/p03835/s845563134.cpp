#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int k, s,sum=0;
	cin >> k >> s;
	int z=0,cnt=0;
	for (int x = k; x >= 0; x--) {
		for (int y = k; y >= 0; y--) {
			z = s - (x + y);
			sum = x + y + z;
			if (0 <= z &&z <= k && sum == s)cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

