#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll ans = 1;
	ll mod = 1e+9+7;
	for (int i = 1; i <= N; i++) {
		ans = (ans*i)%mod;
	}
	cout << ans << endl;
	return 0;
}
