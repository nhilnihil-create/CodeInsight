#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<ii> sii;
typedef set<int> si;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;

const int INF = 1000000000;
const ll MOD = 1000000007;

int main() {FIN
	
	int w, h, n, x, y, a, xr, xl, yt, yb;
	cin >> w >> h >> n;
	xr = w, xl = 0, yt = h, yb = 0;
	while (n--) {
		cin >> x >> y >> a;
		if (a == 1) xl = max(xl, x);
		else if (a == 2) xr = min(xr, x);
		else if (a == 3) yb = max(yb, y);
		else yt = min(yt, y);
	}
	
	cout << (xl <= xr ? xr-xl : 0) * (yb <= yt ? yt-yb : 0) << "\n";
	
	return 0;
}
