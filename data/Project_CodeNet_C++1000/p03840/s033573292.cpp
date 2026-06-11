#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <numeric>
typedef long long ll;
using namespace std;
const int MOD = (int)1e9 + 7;
const ll INF = (ll)1e18 + 7;
#define int long long
#define vint vector<int>
#define pint pair<int, int>
#define pb(a) push_back(a)
#define all(v) v.begin(), v.end()
#define dbg(x) cerr << #x << " = " << (x) << endl
#define yn(b) cout << ((b) ? "Yes" : "No") << endl
#define YN(b) cout << ((b) ? "YES" : "NO") << endl

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int I, O, T, J, L, S, Z;
	int ans1 = 0, ans2 = 0;
	cin >> I >> O >> T >> J >> L >> S >> Z;

	ans1 = (I / 2) * 2 + O + (J / 2) * 2 + (L / 2) * 2;
	if (I > 0 && L > 0 && J > 0)
	{
		I--, J--, L--;
		ans2 = 3 + (I / 2) * 2 + O + (J / 2) * 2 + (L / 2) * 2;
	}

	cout << max(ans1, ans2) << endl;

	return 0;
}