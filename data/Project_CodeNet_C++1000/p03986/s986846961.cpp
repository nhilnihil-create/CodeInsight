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
	// ARC005-A, 1030, 
	string s; cin >> s;
	int ss = s.size();
	int snum = 0;
	string ans;
	rep(i, ss) {
		if (s[i] == 'S') snum++;
		else {
			if (snum == 0) ans += s.substr(i, 1);
			else snum--;
		}
	}
	int as = ans.size();
	rep(i, as) ans.push_back('S');
	cout << ans.size() << endl;
	return 0;
}