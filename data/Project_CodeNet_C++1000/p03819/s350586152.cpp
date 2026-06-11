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

const int N = 3e5+1;
int n, m, Bit[N];

void Update(int p, int val){
	for (; p <= m; p += p&-p) Bit[p] += val;
}

int Get(int p){
	int ans = 0;
	for (; p > 0; p -= p&-p) ans += Bit[p];
	return ans;
}

struct Data{
	int l, r, diff;
	Data(int l_, int r_, int diff_){
		l = l_;
		r = r_;
		diff = diff_;
	}
	Data(){}

};

Data a[N];

bool comp(Data A, Data B){
	return A.diff < B.diff;
}

int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i].l >> a[i].r;
		a[i].diff = a[i].r - a[i].l + 1;
	}

	sort(a + 1, a + 1 + n, comp);

	int cnt = 0; int cur = 1;
	for (int i = 1; i <= m; i++){
		while (cur <= n && a[cur].diff < i){
			Update(a[cur].l, 1); Update(a[cur].r + 1, -1);
			cnt++; cur++;
		}
		int ans = 0;
		for (int j = 0; j <= m; j += i){
			ans += Get(j);
		}		
		cout << ans + n - cnt << '\n';
	}
	return 0;
}