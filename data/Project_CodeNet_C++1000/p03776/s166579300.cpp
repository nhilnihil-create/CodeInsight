/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
#define mem(i,j) memset(i,j,sizeof (i));
#define F first
#define S second
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (long long)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/
#define int ll

int c[51][51];

void init() {
	for(int i = 0; i <= 50; i++)
		c[i][0] = c[i][i] = 1;
	for(int i = 1; i <= 50; i++)
		for(int j = 1; j < i; j++)
			//c[i][j] = c[i][j-1] + c[i-1][j-1];// Wrong
			c[i][j] = c[i-1][j] + c[i-1][j-1];// Correct
	cout << fixed << setprecision(15);
}

signed main() {
	EmiliaMyWife

	init();
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<int>());

	int sum = 0, ans = 0;
	for(int i = 0; i < a; i++)
		sum += arr[i];
	long double x = sum;
	cout << x/a << '\n';

	if(arr[0]==arr[a-1]) {
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if(arr[i] == arr[0])
				cnt++;
		for(int i = a; i <= min(b, cnt); i++)
			ans += c[cnt][i];
	}
	else {
		map<int,int> cnt;
		int w = 0;
		for(int i = 0; i < n; i++)
			cnt[arr[i]]++;
		for(int i = 0; i < a; i++)
			if(arr[i]==arr[a-1])
				w++;
		ans = c[cnt[arr[a-1]]][w];
		//cout << c[3][1] << ' ';
	}
	cout << ans;

	return 0;
}
