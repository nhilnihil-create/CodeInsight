#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	string s; cin >> s;
	string ans;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '0') ans.push_back('0');
		else if(s[i] == '1') ans.push_back('1');
		else if(ans.size() != 0) ans.pop_back();
	}
	cout << ans << endl;
	return 0;
}