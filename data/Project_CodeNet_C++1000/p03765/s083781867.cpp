#include "bits/stdc++.h"

//region Template
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int MOD = 1000000007;

using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

#define finish(x) cout << x; exit(0);
#define fastIO cin.tie(0); cin.sync_with_stdio(false);

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }

//const string USCAO_TAG = "mountains";
void usaco(const string& USACO_TAG) { setIn(USACO_TAG + ".in"); setOut(USACO_TAG + ".out"); }
void print() {}
template<typename T, typename... Args>
void print(T firstArg, Args... args) {
	#ifdef LOCAL
	cout << firstArg << "\t";
	print(args...);
	#endif
}
//endregion

/* Notes:
 * Farah </3
 */

const int MAXN = 1e5 + 6;
const int INF = 2e9;

int a[MAXN], b[MAXN];
int aa[MAXN], bb[MAXN];

int main() {
	#ifdef LOCAL
	setIn("in.txt");
	setOut("out.txt");
	#endif

	string s, t;
	cin >> s >> t;

	int q;
	cin >> q;

	for(int i = 1; i <= s.size(); i++){
		a[i] = a[i - 1] + (s[i - 1] == 'A');
		b[i] = b[i - 1] + (s[i - 1] == 'B');
	}
	for(int i = 1; i <= t.size(); i++){
		aa[i] = aa[i - 1] + (t[i - 1] == 'A');
		bb[i] = bb[i - 1] + (t[i - 1] == 'B');
	}
	for(int i = 0; i < q; i++){
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;

		int af = a[y] - a[x - 1];
		int as = aa[yy] - aa[xx - 1];
		int bf = b[y] - b[x - 1];
		int bs = bb[yy] - bb[xx - 1];

		int c = abs(af - as);

		if(c == 0){
			cout << (abs(bf - bs) % 3 == 0 ? "YES\n" : "NO\n");
			continue;
		}
		else{
			if(af > as){
				bf += c * 2;
			}
			else{
				bs += c * 2;
			}
			cout << (abs(bf - bs) % 3 == 0 ? "YES\n" : "NO\n");
			continue;
		}
	}
}
