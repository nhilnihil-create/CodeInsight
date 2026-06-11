#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int N = (int)s.size();
	int gn = 0, pn = 0;
	int lose = 0, draw = 0, win = 0;
	for(int i=0;i<N;i++) {
		if(gn == pn) {
			gn++;
			if(s[i] == 'p') lose++;
			else draw++;
		} else {
			// pn < gn
			if(s[i] == 'g') {
				pn++;
				win++;
			} else {
				pn++;
				draw++;
			}
		}
	}
	cout << win - lose << endl;
}