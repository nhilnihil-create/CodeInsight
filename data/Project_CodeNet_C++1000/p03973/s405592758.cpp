// In The Name Of Allah
#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
const ll mod = 1e9 + 7;
 
 
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll M = 400 + 10;
const ll N = 100 * 1000 + 10;
 
ll a[N];
 
int main()
{
	faster();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll ans = a[0] - 1, cnt = 2;
	for (int i = 1; i < n; i++)
	{
		if(a[i] == cnt)
			cnt++;
		ans += (a[i] - 1) / cnt;
	}
	cout << ans << endl;
}