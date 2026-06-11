#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string s;
	cin >> s;
	set<char> moko;
	rep(i, s.size()) moko.insert(s[i]);
	if (moko.size() == s.size()) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}