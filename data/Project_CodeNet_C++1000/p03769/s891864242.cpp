#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pie;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LINF = 4e18;
const ll delta = 96181;

ll n;
vector<int> ans;

ll maxBit(ll x) {
	for (ll i = 50; i >= 0; i--)
		if (x & (1LL << i))
			return i;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; n++;
	ll d = maxBit(n);
	for (ll i = d - 1; i >= 0; i--)
		if ((n & (1LL << i)) == 0) {
			ans.push_back(ans.size() + 1);
		}
		else {
			ans.push_back(ans.size() + 1);
			ans.push_back(1);
			for (int j = 0; j < ans.size() - 1; j++)
				ans[j]++;
		}
	int tmp = ans.size();
	for (int i = 1; i <= tmp; i++)
		ans.push_back(i);
	cout << ans.size() << endl;
	for (int i : ans)
		cout << i << ' ';
	cout << endl;
}

