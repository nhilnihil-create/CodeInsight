#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string w;
	cin >> w;
	int s=0;
	set<char> dif;
	multiset<char> many;
	for(int i=0; i<w.size(); i++) {
		dif.insert(w[i]);
		many.insert(w[i]);
	}
	for(auto i : dif) {
		if (many.count(i) % 2 == 0) {
			s++;
		}
	}
	if(s==dif.size()) {
		cout << "Yes";
		return 0;
	}
	cout << "No";
	
	return 0;
}
