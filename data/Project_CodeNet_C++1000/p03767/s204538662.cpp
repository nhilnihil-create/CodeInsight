#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> a(3*n);
	rep(i, 3*n) cin >> a[i];
	sort(a.begin(), a.end());
	lli ans = 0;
	rep(i, n){
		ans+=a[3*n-2*i-2];
	}
	cout << ans << endl;
	return 0;
}
