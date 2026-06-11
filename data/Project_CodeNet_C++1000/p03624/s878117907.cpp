#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string s;
	cin >> s;
	set< char> ss;
	for (auto& e:s) {
		ss.insert(e);
	}
	char ch = 'a';
	for(auto& e:ss) {
		if (ch == e) {
			ch++;
		}
	}
	if (ch > 'z') {
		cout << "None";
	} else {
		cout << ch;
	}
	
	return 0;
}
