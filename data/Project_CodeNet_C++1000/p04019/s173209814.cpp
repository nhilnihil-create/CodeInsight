#include<bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORD(i, m, n) for(int i = m; i >= n; i--)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ld = long double;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int N=0,S=0,E=0,W=0;
	REP(i, s.length()) {
		if(s[i]=='S')S=1;
		else if(s[i]=='N')N=1;
		else if(s[i]=='W')W=1;
		else E=1;
	}
	if(S==N&&W==E)cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}