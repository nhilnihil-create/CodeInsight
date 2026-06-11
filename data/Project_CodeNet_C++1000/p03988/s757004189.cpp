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

int n, ar[N], col[N];

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
		col[ar[i]]++;
	}
	sort(ar + 1, ar + n + 1);

	if(ar[n] % 2 == 0) {
		int st = ar[n] / 2;
		for(int i = 1; i < st; i++)
			if(col[i]) {
				cout << "Impossible";
				return 0;
			}
		if(col[st] != 1) {
			cout << "Impossible";
			return 0;
		}
		for(int i = st + 1; i <= ar[n]; i++) {
			if(!col[i] || col[i] == 1) {
				cout << "Impossible";
				return 0;
			}
		}
		cout << "Possible";
	} 
	else {
		int st = ar[n] / 2 + 1;
		for(int i = 1; i < st; i++)
			if(col[i]) {
				cout << "Impossible";
				return 0;
			}
		if(col[st] != 2) {
			cout << "Impossible";
			return 0;
		}
		for(int i = st + 1; i <= ar[n]; i++) {
			if(col[i] == 0 || col[i] == 1) {
				cout << "Impossible";
				return 0;
			}
		}
		cout << "Possible";
	}
}