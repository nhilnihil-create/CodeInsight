#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll q = 2;
	ll ans = a[0] - 1;
	rep(i, n - 1){
		if(a[i+1] == q){
			q++;
		}else{
			ans += (a[i+1] % q == 0 ? a[i+1] / q - 1: a[i+1] / q);
		}
	}

	cout << ans << endl;
}
