//I finally found out what's in your mind and I hate you!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = (int)1e6 + 3;
const int infint = (int)1e9 + 3;
const int MOD = (int)998244353;
const ll inf = (ll)1e18 + 3;
int n, a[MAXN];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if(i + 1 > a[i + 1])
		{
			int ans = 0;
            for(int j = i + 1; a[j] == i; j++)
				ans ^= 1;
            ans |= (a[i] - i) & 1;
           	cout << (ans ? "First" : "Second");
            return 0;
		}
	}
}
