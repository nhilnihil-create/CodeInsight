#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string sa, sb, sc; cin >> sa >> sb >> sc;
	string ans;
	int a_index = 0;
	int b_index = 0;
	int c_index = 0;
	char now = 'a';
	while (true) {		
		if (now == 'a') {
			if (a_index == sa.size()) {
				ans = "A";
				break;
			}
			now = sa[a_index];
			a_index++;		
		}
		else if (now == 'b') {
			if (b_index == sb.size()) {
				ans = "B";
				break;
			}
			now = sb[b_index];
			b_index++;		
		}
		else {			
			if (c_index == sc.size()) {
				ans = "C";
				break;
			}
			now = sc[c_index];
			c_index++;		
		}
	}
	cout << ans << endl;
	return 0;
}