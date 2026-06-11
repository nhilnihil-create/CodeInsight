#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	string S;
	bool judge;

	judge = false;

	cin >> S;
	
	for (int i = 0; i < S.size() -1; i++) {
		for (int j = i + 1; j < S.size(); j++) {
			if (S[i] == S[j]) judge = true;
		}
	}

	if (judge) cout << "no";
	else cout << "yes";

	return 0;

}