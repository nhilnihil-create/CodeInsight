#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

const int MX = 1e5 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

#define F0R(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ps(x) cout << x << "\n";
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
		ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); 
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

int a, b;

int main() {
	cin >> a >> b;
	if (a == 0 || b == 0) {
		ps("Zero");
		return 0;
	}
	else if (a > 0 && b > 0) {
		ps("Positive");
		return 0;
	}
	if (b > a) swap(a, b);
	//cout << a << " " << b << "\n";
	if (a > 0 && b < 0) {
		ps("Zero");
		return 0;
	}
	else {
		int dist = b - a + 1;
		if (dist & 1) {
			ps("Negative");
			return 0;
		}
		else {
			ps("Positive");
			return 0;
		}
	}
}





