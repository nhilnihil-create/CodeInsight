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
	string S; cin >> S;
	string T, ans = "YES";
	int i = S.size() - 1;
	while(i >= 0) {
		if(S[i] != 'm' && S[i] != 'r' && S[i] != 'e') {
			ans = "NO"; break;
		}
		string s;
		if(S[i] == 'm') {
			if(i - 4 < 0) {
				ans = "NO"; break;
			}
			s = S.substr(i - 4, 5);
			if(s == "dream") i -= 5;
			else {
				ans = "NO"; break;
			}
		}
		else if(S[i] == 'e') {
			if(i - 4 < 0) {
				ans = "NO"; break;
			}
			s = S.substr(i - 4, 5);
			if(s == "erase") i -= 5;
			else {
				ans = "NO";
				break;
			}
		}
		else if(S[i] == 'r') {
			if(i - 5 < 0) {
				ans = "NO"; break;
			}
			else {
				s = S.substr(i - 5, 6);
				if(s == "eraser") i -= 6;
				else {
					if(i - 6 < 0) {
						ans = "NO"; break;
					}
					else {
						s = S.substr(i - 6, 7);
						if(s == "dreamer") i -= 7;
						else {
							ans = "NO"; break;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
