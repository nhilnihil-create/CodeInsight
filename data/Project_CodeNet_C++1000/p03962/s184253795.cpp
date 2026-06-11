#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long int

#define M 1e18

void solve() {
	set<int> s;
	int n = 3,num;
	while(n-- && cin >> num) {
		s.insert(num);
	}
	cout << s.size() << endl;
}
		
			
		

int32_t main() {
	IOS;
	solve();
	return 0;
}
