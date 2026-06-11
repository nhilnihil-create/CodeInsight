#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(63);

lli n, m, k, ar[N], op[N], p[N][LOG], d[N], pp[N], t[N];

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> ar[i];
	for(int i = 1; i < n; i++)
		d[i] = ar[i + 1] - ar[i];
	cin >> m >> k;
	for(int i = 1; i <= m; i++)
		cin >> op[i];
	for(int i = 1; i < n; i++)
		p[i][0] = i;
	for(int i = 1; i <= m; i++)
		swap(p[op[i]][0], p[op[i] - 1][0]);
	for(int i = 1; i < LOG; i++)
		for(int j = 1; j < n; j++)
			p[j][i] = p[p[j][i - 1]][i - 1];
	for(int i = 1; i <= n; i++)
		pp[i] = i;
	for(lli i = 0; i < LOG; i++)
		if((1ll << i) & k) {
			for(int j = 1; j < n; j++)
				t[j] = d[p[j][i]];
			for(int j = 1; j < n; j++)
				d[j] = t[j];
		}
	for(int i = 2; i < n; i++)
		ar[i] = ar[i - 1] + d[i - 1];
	for(int i = 1; i <= n; i++)
		cout << ar[i] << endl;
}