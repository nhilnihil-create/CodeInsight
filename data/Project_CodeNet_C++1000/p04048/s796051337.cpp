#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int go(int a, int b, int c) {
	if(a % c == 0) {
		return 2 * a;
	}
	int ans = 0;
	ans += a / c * 2 * c + c;
	ans += go(c-a%c, c, a%c) + a % c;
	return ans;
}

signed main()
{
	IO_OP;
	
	int n, x;
	cin >> n >> x;
	cout << x + go(x, n, n-x) << endl;
	
}
