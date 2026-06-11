		#include<bits/stdc++.h>
		#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		#define endl "\n"

		using namespace std;
	
	int main() {	
		int n; cin >> n;
		string y; cin >> y;
		int s = 0;
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			y[i] == 'I' ? ++s : --s;
			mx = max(s, mx);
		}
		cout << mx;
		return 0;
		}
	
