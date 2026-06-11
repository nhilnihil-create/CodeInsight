#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;
using namespace std;
 
const int MAXN = 1000 + 20, MAXM = 20, MOD = 1000 * 1000 * 1000 + 7;
const long long INF = 1e9 + 10;
char c[MAXN][MAXN];
int a[MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int n, m;
map <int, int> m1;

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void solve() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	bool nob = 0;
	while (1) {
		int mn = INF, sum = 0, od = 0, ev = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];	
			mn = min(a[i], mn);
			od += a[i] % 2;
			ev += (a[i] - 1) % 2;
		}
		
		if (mn == 1) {
			if (nob == 0) {
				if ((sum - n) % 2 == 1) 
					cout << "First" << endl;
				else
					cout << "Second" << endl;
			}
			else {
				if ((sum - n) % 2 == 0) 
					cout << "First" << endl;
				else
					cout << "Second" << endl;
			}
			return;
		}
		else {
			int cnt = 0;
			int g = 0;
			if (ev % 2 == 1) {
				if (nob == 0)
					cout << "First" << endl;
				else
					cout << "Second" << endl;
				return;
			}
			if (od > 1) {
				if (nob == 1)
					cout << "First" << endl;
				else
					cout << "Second" << endl;
				return;
			}
			
			for (int i = 0; i < n; i++) {
				if (a[i] % 2 == 1) {
					cnt++;
					a[i]--;
				}
				g = __gcd(g, a[i]);
			}
			for (int i = 0; i < n; i++)	
				a[i] /= g;
			
			nob ^= 1;
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}