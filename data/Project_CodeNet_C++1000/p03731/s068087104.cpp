#include<bits/stdc++.h>

using namespace std;

int ans, n, t, a[200001];

int main(){
	cin >> n >> t;
	for(int i = 0; i < n; ++i) cin >> a[i];
	a[n] = a[n-1] + t;
	for(int i = 0; i < n; ++i) ans += min(t, abs(a[i]-a[i+1]));
	cout << ans << endl;
}