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
const int LOG = (int)(20);

lli n, k, sum, ar[N], d[N];

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
		sum += ar[i];
	}

	for(int i = 1; i <= n; i++)
		d[i] = ar[i + 1 > n ? 1 : i + 1] - ar[i];
	if(sum % (n * (n + 1) / 2) != 0) {
		cout << "NO";
		return 0;
	}
	k = sum / (n * (n + 1) / 2);
	for(int i = 1; i <= n; i++) {
		if(k < d[i]|| (k - d[i]) % n != 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}