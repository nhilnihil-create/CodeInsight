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
	char ans;
	while (true) {
		if (who == 'a') {
			if (tmp_a == na) {
				ans = 'A';
				break;
			}
			who = sa[tmp_a++];
		}
		else if (who == 'b') {
			if (tmp_b == nb) {
				ans = 'B';
				break;
			}
			who = sb[tmp_b++];
		}
		else { // who == 'c'
			if (tmp_c == nc) {
				ans = 'C';
				break;
			}
			who = sc[tmp_c++];
		}
	}
	cout << ans << endl;
	return 0;
}