#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

const int N = 1e5+1;

int n, a[N], val[N], b[N];
long res[N];
vector <int> pos[N];

int main()
{
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++){
		int x = lower_bound(a + 1, a + 1 + n, b[i]) - a;
		val[x] = b[i];
		pos[x].push_back(i);
	}
	int pre = -INF, x = INF;
	long cnt = 0;
	for (int i = n; i >= 0; i--){
		if (i == 0){
			res[x] += cnt * pre;
			break;
		}
		if (pos[i].size() == 0) continue;
		if (pre == -INF){
			x = pos[i][0];
			pre = val[i];
			cnt += pos[i].size();
		}	
		else {
			res[x] += cnt * (pre - val[i]);
			if (pos[i][0] < x) x = pos[i][0];
			cnt += pos[i].size();
			pre = val[i];
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << '\n';
	return 0;
}