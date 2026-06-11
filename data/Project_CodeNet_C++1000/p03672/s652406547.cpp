#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	string s; cin >> s;
	int ans = 0;
	s.erase(s.length()-1);
	while (1) {
		if (s.length() % 2 == 0) {
			if (memcmp(&s[0], &s[s.length()/2], s.length()/2) == 0) {
				ans = s.length();
				break;
			}
		}
		s.erase(s.length()-1);
	}
	cout << ans << endl;
}