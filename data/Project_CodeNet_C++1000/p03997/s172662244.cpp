#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

void solve() {
	int a,b,h;
	cin >> a;
	cin >> b;
	cin >> h;
	
	cout << (min(a,b)*h) + ((max(a,b)-min(a,b))*h)/2 << endl;
}
		
			
		

int32_t main() {
	IOS;
	solve();
	return 0;
}
