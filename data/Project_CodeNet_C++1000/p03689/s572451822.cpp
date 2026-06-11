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

const int N = (int)(1e3 + 5);
const int LOG = (int)(20);

lli H, W, h, w, ar[N][N], tot;

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> H >> W >> h >> w;
	if(H % h == 0 && W % w == 0) {
		cout << "No";
		return 0;
	}
	cout << "Yes" << endl;
	for(int i = 1; i <= H; i++)
		for(int j = 1; j <= W; j++)
			ar[i][j] = -1000;
	if(H % h != 0) {
		for(int i = 1; i <= H; i += h)
			for(int j = 1; j <= W; j++)
				ar[i][j] = 1000 * (h - 1) - 1;
	}
	else if(W % w != 0) {
		for(int i = 1; i <= H; i++)
			for(int j = 1; j <= W; j += w)
				ar[i][j] = 1000 * (w - 1) - 1;
	}
	for(int i = 1; i <= H; i++, cout << endl)
		for(int j = 1; j <= W; j++)
			cout << ar[i][j] << spc;
}