#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int main() {
    string s;
	int k;
	cin >> s >> k;

	rep(i, (int)s.length()){
		if (s[i] == 'a')
			continue;
		if ('z' - s[i] + 1 <= k){
			k -= ('z' - s[i] + 1);
			s[i] = 'a';
		}
	}
	k = k % 26;
	s[s.length()-1] += k;
	cout << s << endl;
}
