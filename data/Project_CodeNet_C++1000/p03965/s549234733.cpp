#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str; int rock = 0, paper = 0, ans = 0;
	for(auto ch: str) {
		if(ch == 'g') {
			if(paper < rock) ++paper, ++ans;
			else ++rock;
		} else {
			if(paper < rock) ++paper;
			else ++rock, --ans;
		}
	}

	cout << ans << endl;
}