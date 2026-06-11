#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;
	ll a[n+1], s[n+1], m[n+1];
	for(int i=1; i<=n; i++) cin >> a[i];
	s[0]=0, m[0]=0;
	for(int i=1; i<=n; i++){
		s[i]=s[i-1]+a[i];
		m[i]=m[i-1]+max(0ll, a[i]);
	}

	ll ans=0;
	for(int i=1; i+k<=n+1; i++){
		ll tmp=max(0ll, s[i+k-1]-s[i-1])+m[i-1]+(m[n]-m[i+k-1]);
		ans=max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}