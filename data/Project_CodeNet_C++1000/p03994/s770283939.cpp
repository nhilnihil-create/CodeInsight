#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
constexpr auto INF = 4000000000; //4*10^9;
constexpr auto MOD = 1000000007; //10^9+7;


char nextab(char c) {
	if (c == 'z') return 'a';
	else return c + 1;
}


int main(){
	
	string s;
	cin >> s;
	int k;
	cin >> k;

	vector<char> c(s.size());
	rep(i, s.size())c[i] = s[i];

	rep(i, s.size()-1) {
		if (c[i] == 'a') continue;
		if ('z' - c[i] + 1 <= k) {
			for (;c[i] != 'a' && k > 0;) {
				c[i] = nextab(c[i]);
				k--;
			}
		}
	}

	k %= 26;

	if (k > 0) {
		rep(i, k) {
			c[s.size() - 1] = nextab(c[s.size() - 1]);
		}
	}

	rep(i,s.size())	cout << c[i];
	cout << endl;
}