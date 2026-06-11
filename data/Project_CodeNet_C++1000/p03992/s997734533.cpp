#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define ALL(a) (a).begin(),(a).end()
#define MOD 1e9+7
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	string s; cin >> s;
	string ans = s.substr(0, 4) + " " + s.substr(4, 8);
	co(ans);
	return 0;
}
