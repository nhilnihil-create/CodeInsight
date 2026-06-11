#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	set<char> p;
	for(int i = 0; i < n; ++i) {
		p.insert(s[i]);
	}
	if ((int)p.size() == n) {
		cout << "yes";
	}else {
		cout << "no";
	}
}

















