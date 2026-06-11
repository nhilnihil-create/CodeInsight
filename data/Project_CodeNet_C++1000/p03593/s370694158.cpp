#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 1;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
ll n, m, x = 0, y,z,w,h, sum= 0, ans = 0;
string s, t;
int main() {
	cin >> h >> w; char c;
	map<char, int> mp;
	rep(i, h) {
		rep(j, w) {
			cin >> c;
			mp[c]++;
		}
	}
	for (auto k : mp) {
		sum += k.second % 2;
		if (k.second % 4 > 1) ans++;
	}
	if (h % 2 && w % 2) {
		if (ans > w / 2 + h / 2 || sum > 1) {
			cout << "No" << endl;
			return 0;
		}
	}
	else if (h % 2 || w % 2) {
		if (sum > 0 || ans > h % 2 * w / 2 + w % 2 * h / 2) {
			cout << "No" << endl;
			return 0;
		}
	}
	else {
		if (sum > 0 || ans > 0) {
			cout << "No" << endl;
			return 0;
		}
	}cout << "Yes" << endl;
}