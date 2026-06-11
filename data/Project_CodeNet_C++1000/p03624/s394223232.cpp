#include<iostream>
#include<string>

using namespace std;

int main() {
	string S, alpha = { "abcdefghijklmnopqrstuvwxyz" };
	bool flag[26], flag2 = true;

	for (int i = 0; i < 26; i++) {
		flag[i] = false;
	}

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < alpha.size(); j++) {
			if (S[i] == alpha[j]) {
				flag[j] = true;
			}
		}
	}
	for (int i = 0; i < alpha.size(); i++) {
		if (flag[i] == false) {
			cout << alpha[i] << endl;
			flag2 = false;
			break;
		}
	}
	if (flag2 == true) {
		cout << "None" << endl;
	}


	return 0;
}