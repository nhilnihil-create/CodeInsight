#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	rep(i,3) {
		if (a[i]%2==0) {
			cout << 0 << endl;
			return 0;
		}
	}
	int d = a[2]/2, u = a[2] - d;
	ll ans = (u-d)*(ll)a[0]*(ll)a[1];
	cout << ans << endl;

	return 0;
}
