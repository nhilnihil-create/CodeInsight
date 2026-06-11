#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define MOD ((int)(1e9) + 7)
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define filename "lynext"
#define freop freopen(filename ".cik","w",stdout);freopen(filename ".gir","r",stdin)
const long long int N = ((long long int)2e5) + 5;
const long long int M = ((long long int)1e3) + 5;
const long long int llinf = (long long int)1e18;
const int inf = INT_MAX;
typedef long long int lli;

lli n;
lli arr[N];
lli hist1[N];
lli hist2[N];
lli ans;

void init ()
{
	stack<lli> s;
	for (lli i = 1; i <= n; i++)
	{
		while (!s.empty() && arr[s.top()] > arr[i])
			s.pop();
		if (s.empty())
			hist1[i] = 0;
		else
			hist1[i] = s.top();
		s.push(i);
	}
	while (!s.empty())
		s.pop();
	for (lli i = n; i >= 1; i--)
	{
		while (!s.empty() && arr[s.top()] > arr[i])
			s.pop();
		if (s.empty())
			hist2[i] = n + 1;
		else
			hist2[i] = s.top();
		s.push(i);
	}

}

int main ()
{
	fast;
	//freop;
	cin >> n;
	for (lli i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init();
	for (lli i = 1; i <= n; i++)
	{
		ans += (i - hist1[i]) * (hist2[i] - i) * arr[i];
	}
	cout << ans << "\n";
}
