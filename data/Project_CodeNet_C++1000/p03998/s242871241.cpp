#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
		
	string sa, sb, sc; cin >> sa >> sb >> sc;

	int na = sa.size();
	int nb = sb.size();
	int nc = sc.size();
	int tmp_a = 0;
	int tmp_b = 0;
	int tmp_c = 0;
	char who = 'a';
	while (true) {
		if (tmp_a == na + 1|| tmp_b == nb + 1 || tmp_c == nc + 1) {
			break;
		}
		if (who == 'a') {
			who = sa[tmp_a++];
		}
		else if (who == 'b') {
			who = sb[tmp_b++];
		}
		else { // who == 'c'
			who = sc[tmp_c++];
		}
	}
	
	if(tmp_a == na + 1) cout << 'A' << endl;
	else if (tmp_b == nb + 1) cout << 'B' << endl;
	else if (tmp_c == nc + 1) cout << 'C' << endl;	
	return 0;
}