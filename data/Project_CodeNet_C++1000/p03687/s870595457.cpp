#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <assert.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ARC016-A, 993, 
	string s; cin >> s;
	int ss = s.size();
	int ans = iINF;
	rep(i, 26) {
		char cur = 'a' + i;
		vector<int> pos;
		pos.push_back(-1);
		rep(j, ss) {
			if (s[j] == cur) pos.push_back(j);
		}
		if (pos.size() == 1) continue;
		pos.push_back(ss);
		int tmpans = 0;
		rep(j, pos.size() - 1) tmpans = max(tmpans, pos[j + 1] - pos[j] - 1);
		ans = min(ans, tmpans);
	}
	cout << ans << endl;
	return 0;
}