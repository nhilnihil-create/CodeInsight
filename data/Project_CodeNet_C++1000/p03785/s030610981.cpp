#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, c, k;

int main(void){
	cin >> n >> c >> k;
	vector<lli> t(n);
	rep(i, n) cin >> t[i];
	sort(t.begin(), t.end());
	lli ans = 0;
	lli i = 0;
	while(i < n){
		lli l = t[i];
		lli p = 0;
		while(i < n && p < c && t[i] <= l+k){
			p++;
			i++;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}
