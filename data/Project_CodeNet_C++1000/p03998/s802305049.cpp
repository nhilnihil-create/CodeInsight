#include <bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)(x.size()))
#define FOR(i,s,n) for (ll i = (s); (i) < (n); ++i)
#define FORD(i,s,l) for (ll i = (s); (i) >= l; --i)
#define F first
#define S second
#define TC int __tc; cin >> __tc; FOR(case_num,1,__tc+1)
#define TEST(x,i) ((x)&(1ll<<(i)))
#define SET(x,i) ((x)|(1ll<<(i)))
#define FLIP(x,i) ((x)^(1ll<<(i)))
#define CLEAR(x,i) ((x)&~(1ll<<(i)))

const double pi = 4 * atan(1);
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 200005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	map<char,string> f;
	cin >> f['a'];
	cin >> f['b'];
	cin >> f['c'];
	
	reverse(f['a'].begin(),f['a'].end());
	reverse(f['b'].begin(),f['b'].end());
	reverse(f['c'].begin(),f['c'].end());
	
	char c = 'a';
	while(f[c].length()) {
		char c2 = f[c].back();
		f[c].pop_back();
		c = c2;
	}
	
	cout << (char)toupper(c) << "\n";

}
