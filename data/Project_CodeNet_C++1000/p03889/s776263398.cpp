#include <bits/stdc++.h>
using namespace std;
int main() {
	string S;
	cin >> S;
	int L = S.length();
	bool result = true;
	for(int i = 0; i < L; i++) {
		switch(S[i]) {
			case 'd':
				if(S[L - i - 1] != 'b') result = false;
				break;
			case 'b':
				if(S[L - i - 1] != 'd') result = false;
				break;
			case 'p':
				if(S[L - i - 1] != 'q') result = false;
				break;
			case 'q':
				if(S[L - i - 1] != 'p') result = false;
				break;
		}
	}
	cout << (result ? "Yes" : "No") << endl;
	return 0;
}