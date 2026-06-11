#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int h, w;
	cin >> h >> w;
	V<string> s(h);
	rep(i, h)cin >> s[i];

	map<char, int> mp;
	rep(i, h)rep(j, w)mp[s[i][j]]++;

	bool ok = true;

	if (h % 2 == 0 && w % 2 == 0) {
		for (auto x : mp)if (x.second % 4)ok = false;
		cout << (ok ? "Yes" : "No") << endl;
	}
	else if (h % 2 == 0 || w % 2 == 0) {
		int ev;
		if (h % 2)ev = w;
		else ev = h;
		int cnt = 0;
		for (auto x : mp) {
			if (x.second % 2)ok = false;
			if (x.second % 4)cnt++;
		}
		if (ok && cnt <= ev / 2)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else {
		int cnto = 0, cnte = 0;
		for (auto x : mp) {
			if (x.second % 2)cnto++;
			else if (x.second % 4)cnte++;
		}
		if (cnto==1&&cnte<=h/2+w/2)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}