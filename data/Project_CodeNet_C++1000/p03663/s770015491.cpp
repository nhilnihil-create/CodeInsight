#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

signed main() {
	string s;
	int a = 1, b = 11;
	while (a != b) {
		int t = (a + b) / 2;
		if (b - a == 1)t = b;
		cout << "? 1" << string(t - 1, '0') << endl;
		string res; cin >> res;
		if (res == "N")b = t - 1;
		else a = t;
	}
	if (a == 11) {//最初が1であとは0
		a = 1; b = 10;//最小の"Y"
		while (a != b) {
			int t = (a + b) / 2;
			cout << "? " << string(t, '9') << endl;
			string res; cin >> res;
			if (res == "Y")b = t;
			else a = t + 1;
		}
		cout << "! 1" << string(a - 1, '0') << endl;
		return 0;
	}
	rep(i, a) {
		int l = (i == 0 ? 1 : 0), r = 9;//"Y"になる最小
		while (l != r) {
			int t = (l + r) / 2;
			cout << "? " << s << (char)('0' + t) << string(10 - s.size(), '9') << endl;
			string res; cin >> res;
			if (res == "Y")r = t;
			else l = t + 1;
		}
		s += '0' + l;
	}
	cout << "! " << s << endl;
}