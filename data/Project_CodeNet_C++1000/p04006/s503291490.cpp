#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	ll x;
	cin >> n >> x;
	ll a[n];
	for(int i=0; i<n; i++) cin >> a[i];

	ll b[n][n];
	for(int i=0; i<n; i++){
		b[i][0]=a[i];
		for(int j=0; j<n-1; j++){
			b[i][j+1]=min(b[i][j], a[(i-j-1+n)%n]);
		}
	}

	ll ans=20000*(ll)(1e9);
	for(int k=0; k<=n-1; k++){
		ll tmp=k*x;
		for(int j=0; j<n; j++){
			tmp+=b[j][k];
		}
		ans=min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}