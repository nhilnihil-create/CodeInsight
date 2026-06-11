#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string sa, sb, sc;
	cin >> sa >> sb >> sc;

	char turn = 'a';
	char ans;


	while (true) {
		if (turn == 'a') {
			if (sa.size() == 0) {
				ans = 'A';
				break;
			}
			turn = sa[0];
			sa.erase(sa.begin() + 0);
		}
		else if (turn == 'b') {
			if (sb.size()==0) {
				ans = 'B';
				break;
			}
			turn = sb[0];
			sb.erase(sb.begin() + 0);
		}
		else if (turn == 'c') {
			if (sc.size()==0) {
				ans = 'C';
				break;
			}
			turn = sc[0];
			sc.erase(sc.begin() + 0);

		}

	}

	cout << ans << endl;

}