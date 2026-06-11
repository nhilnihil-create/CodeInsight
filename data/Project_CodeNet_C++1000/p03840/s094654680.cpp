#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"
#include "set"
#include "stack"
#include "tuple"

#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define intinf 1000000000
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define P pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;


int main() {
	ll ai, ao, gomi, aj, al, ans;
	cin >> ai >> ao >> gomi >> aj >> al;
	ans = ao;
	if (ai % 2 + aj % 2 + al % 2 >= 2 && ai != 0 && aj != 0 && al != 0) {
		--ai;
		--aj;
		--al;
		ans += 3;
	}
	ans += ai + aj + al - (ai % 2 + aj % 2 + al % 2);
	cout << ans << endl;
	return 0;
}