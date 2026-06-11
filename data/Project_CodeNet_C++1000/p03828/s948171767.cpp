#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool is_prime(int n) {
	if (n==1) return false;
	else {
		bool flag = true;
		for(int i=2;i*i<=n;i++)
			if (n%i==0) flag = false;
		return flag;
	}
}

int main() {
	int n;
	ll p = 1e9+7;
	cin >> n;
	vector<int> bai(n+1,0);
	vector<int> prime;
	for(int i=2;i<=n;i++) if (is_prime(i)) prime.push_back(i);
	for(int i=2;i<=n;i++) {
		int m = i;
		int idx_p = 0;
		while(m>1) {
			if (m%prime[idx_p]==0) {
				m/=prime[idx_p];
				bai[prime[idx_p]]++;
			}
			else idx_p++;
		}
	}
	ll ans = 1;
	for (ll i=2;i<=n;i++) {
		ans = (ans * (ll)(bai[i]+1)) % p;
		//printf("%d %d\n", i, bai[i]);
	}
	cout << ans << endl;

	return 0;
}
