#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll ans = 1;
	int lst = 0;
	memset(d, 63, sizeof(d));
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		d[i] = min(i, lst+1>>1);
		if (i)
			d[i] = min(d[i], 1+d[i - 1]);
		ans = ans * (d[i]+1) % MOD;
		lst = x;
	}
	cout << ans << "\n";
	return 0;
}
