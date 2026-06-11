// ABC072B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i += 2) {
		cout << s[i];
	}
	cout << endl;

	return 0;
}
