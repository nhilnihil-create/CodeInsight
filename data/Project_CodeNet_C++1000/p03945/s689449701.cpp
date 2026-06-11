#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	long counter = 0;
	long bw = s[0];
	for (long i = 0; i < s.size(); i++) {

		if (bw != s[i]) {
			bw = s[i];
			counter++;
		}

	}
	cout << counter << endl;
}