#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

ll a[10], x, ans;
int main()
{
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6];                    
	
	x = 0;
	if(x <= a[0] && x <= a[3] && x <= a[4])
		ans = max(ans, (a[0] - x) / 2 * 2 + a[1] + (a[3] - x) / 2 * 2 + (a[4] - x) / 2 * 2 + x * 3);
	
	x = 1;
	if(x <= a[0] && x <= a[3] && x <= a[4])
		ans = max(ans, (a[0] - x) / 2 * 2 + a[1] + (a[3] - x) / 2 * 2 + (a[4] - x) / 2 * 2 + x * 3);
	
	cout << ans;
	return 0;
}
