#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string s;
	cin >> s;
	int l = s.size();
	map<char, int> angle;
	rep(i, l) {
		angle[s[i]]++;
	}
	bool ns = (angle['N']&&angle['S']) || (!angle['N']&&!angle['S']);
	bool ew = (angle['E']&&angle['W']) || (!angle['E']&&!angle['W']);
	if (ns && ew) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}