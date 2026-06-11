#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

void solve() {
	int n,k,a,b,ans = 0;
 	cin >> n;
 	cin >> k;
 	cin >> a;
 	cin >> b;
 	
 	ans += (min(n,k))*a + (max(0, n-k))*b;
 	
 	cout << ans;
 	
}
		
			
		

int32_t main() {
	IOS;
	solve();
	return 0;
}
