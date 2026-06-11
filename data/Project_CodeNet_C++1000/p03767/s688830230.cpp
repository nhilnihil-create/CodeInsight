#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	ll a[3*N];
	rep(i,3*N) cin >> a[i];
	sort(a,a+3*N);
	ll ans = 0;
	for (int i = N; i < 3*N; i+=2) {
		ans += a[i];	
	}
	cout << ans << endl;
	return 0;
}
