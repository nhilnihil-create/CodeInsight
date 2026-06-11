#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long int

#define M 1e18

void solve() {
	int a,b,c;
	cin >> a >> b >> c;
	
	if(a == b && a == c) {
		cout << 1 << endl;
	} else if(a == b && a != c) {
		cout << 2 << endl;
	} else if(a != b && a == c) {
		cout << 2 << endl;
	} else if(a != b && b == c) {
		cout << 2 << endl;
	} else {
		cout << 3 << endl;
	}
}
		
			
		

int32_t main() {
	IOS;
	solve();
	return 0;
}
