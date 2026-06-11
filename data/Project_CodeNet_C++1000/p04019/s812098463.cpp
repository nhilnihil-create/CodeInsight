#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = 1001002003004005006ll;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	map<char, int> mp;
	rep(i, s.size()) mp[s[i]]++;
	if (mp.size() == 4) cout << "Yes" << endl;
	else if (mp['N'] && mp['S'] && !mp['W'] && !mp['E']) cout << "Yes" << endl;
	else if (!mp['N'] && !mp['S'] && mp['W'] && mp['E']) cout << "Yes" << endl;
	else if (!mp['N'] && !mp['S'] && !mp['W'] && !mp['E']) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}