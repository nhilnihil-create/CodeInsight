#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> packs(3, 0);
	for (int i = 0; i < 3; i++){
		cin >> packs[i];
	}
	sort(packs.begin(), packs.end());
	if (packs[0] == (packs[1] + packs[2])) cout << "Yes" << endl;
	else if ((packs[0] + packs[1]) == packs[2]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
