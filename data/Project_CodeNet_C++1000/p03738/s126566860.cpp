#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int mod = 1e9 + 7;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int n = (int)s1.size();
	int m = (int)s2.size();
	if (n > m) {
		cout << "GREATER";
		return 0;
	}else if (n < m) {
		cout << "LESS";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (s1[i] > s2[i]) {
			cout << "GREATER";
			return 0;
		}
		if (s1[i] < s2[i]) {
			cout << "LESS";
			return 0;
		}	
	}
	cout << "EQUAL";
}

















