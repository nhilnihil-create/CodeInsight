#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string s;
	cin >> s;
	bool getA = false;
	int a, z = 0;
	rep(i, s.size()) {
		if (s[i] == 'A'&& !getA) {
			a = i;
			getA = true;
		}
		if (s[i] == 'Z') z = max(z, i);
	}
	cout << z-a+1 << endl;
	return 0;
}