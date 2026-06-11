#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
//#define int long long

void solve() {
	int len;
	string a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	
	char curr = 'A';
	int a_ind = 0;
	int b_ind = 0;
	int c_ind = 0;
	
	while(true) {
		if(curr == 'A') {
			len = a.length();
			if(a_ind == len) {
				cout << "A" << endl;
				break;
			}
			
			curr = a[a_ind]-32;
			a_ind++;
			
		} else if(curr == 'B') {
			len = b.length();
			if(b_ind == len) {
				cout << "B" << endl;
				break;
			}
			curr = b[b_ind]-32;
			b_ind++;
		} else {
			len = c.length();
			if(c_ind == len) {
				cout << "C" << endl;
				break;
			}
			curr = c[c_ind]-32;
			c_ind++;
		}
	}

}
		
			
		

int32_t main() {
	IOS;
	solve();
	return 0;
}
