#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD ((int)(1e9) + 7)
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define filename "lynext"
#define freop freopen(filename ".cik","w",stdout);freopen(filename ".gir","r",stdin)
const long long int N = ((long long int)2e3) + 5;
const long long int M = ((long long int)1e3) + 5;
const long long int llinf = (long long int)1e18;
const int inf = INT_MAX;
typedef long long int lli;

lli n, x;
lli arr[N];
lli tut[N];
lli ans = llinf;

int main ()
{
	fast;
	//freop;
	cin >> n >> x;
	for (lli i = 1; i <= n; i++)
	{
		cin >> arr[i];
		tut[i] = llinf;
	}
	for (lli k = 0; k < n; k++)
	{
		for (lli i = 1; i <= n; i++)
		{
			lli ind = i - k;
			ind += n;
			ind %= n;
			ind++;
			tut[i] = min(tut[i], arr[ind]);
		}
		lli a = 0;
		for (lli i = 1; i <= n; i++)
		{
			a += tut[i];
		}
		ans = min(ans,a + (k * x));
	}
	cout << ans << "\n";
}
