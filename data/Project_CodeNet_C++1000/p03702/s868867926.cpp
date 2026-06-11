#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
const ll MOD = 1000000007;
//const ll MOD = 998244353;

int main() {
	ll N, B, A;
	cin >> N >> A >> B;
	vector<ll> H(N);
	for (int i = 0;i < N;i++) {
		cin >> H[i];
	}
	sort(all(H));
	
	ll ng = 0, ok = 1000000000, mid, cnt;
	vector<int> S(N);
	while (ng + 1 != ok) {
		mid = (ok + ng) / 2;
		cnt = 0;
		for (int i = 0;i < N;i++) {
			S[i] = max(0LL, H[i] - mid * B);
			if (S[i])cnt += (S[i] - 1) / (A - B) + 1;
		}
		if (cnt <= mid) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}
	cout << ok << endl;
}