#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include <bitset>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#include<string>
typedef long long ll;
using namespace std;
string s;
int main() {
	cin >> s;
	int lenn=0, lene=0, lens=0, lenw=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'N') {
			lenn=1;
		}
		else if (s[i] == 'W') {
			lenw=1;
		}
		else if (s[i] == 'E') {
			lene=1;
		}
		else {
			lens=1;
		}
	}
	if ((lenn^lens)||(lenw^lene)) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}