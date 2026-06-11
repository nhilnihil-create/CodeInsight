#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD ((int)(1e9) + 7)
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define filename "lynext"
#define freop freopen(filename ".cik","w",stdout);freopen(filename ".gir","r",stdin)
const long long int N = ((long long int)1e5) + 5;
const long long int M = ((long long int)1e3) + 5;
const long long int llinf = (long long int)1e18;
const int inf = INT_MAX;
typedef long long int lli;

lli n,l;
lli arr[N];
lli ind = -1;

int main ()
{
	fast;
	//freop;
	cin >> n >> l;
	for (lli i = 1; i <= n; i++)
		cin >> arr[i];
	for (lli i = 1; i <= n - 1; i++)
	{
		if (arr[i] + arr[i + 1] >= l)
		{
			ind = i;
		}
	}
	if (ind == -1)
		return cout << "Impossible\n",0;
	cout << "Possible\n";
	for (lli i = 1; i < ind; i++)
	{
		cout << i << "\n";
	}
	for (lli i = n - 1; i >= ind + 1; i--)
	{
		cout << i << "\n";
	}
	cout << ind << "\n";
}
