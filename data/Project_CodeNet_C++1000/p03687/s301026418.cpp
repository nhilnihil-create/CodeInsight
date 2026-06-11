#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string S;
	cin >> S;
	int N = S.length();
	int MIN = 100;
	for (int i = 0; i < N; i++) {
		char key = S[i];
		int now = 0, maxdif = 0;
		for (int j = 0; j < N; j++) {
			if (S[j] == key) {
				maxdif = max(now, maxdif);
				now = 0;
			}
			else now++;
		}
		maxdif = max(now, maxdif);
		MIN = min(MIN, maxdif);
	}
	cout << MIN << endl;

}