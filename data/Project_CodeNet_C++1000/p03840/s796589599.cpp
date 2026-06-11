#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(v) v.begin(),v.end()

const int maxn = 1e5 + 100;
const ll inf = 2e18, mod = 1e9 + 7;

ll aI, aO, aT, aJ, aL, aS, aZ, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> aI >> aO >> aT >> aJ >> aL >> aS >> aZ;
	ll cntI = (aI / 2) * 4, cntJ = (aJ / 2) * 4, cntL = (aL / 2) * 4;
	ans = cntI + cntJ + cntL;
	//cerr << '#' << ans << endl;
	if (aI && aJ && aL)
	{
		aI--, aJ--, aL--;
		cntI = (aI / 2) * 4, cntJ = (aJ / 2) * 4, cntL = (aL / 2) * 4;
		ans = max(ans, cntI + cntJ + cntL + 6);
	}
	cout << (ans + aO * 2) / 2 << endl;
}

