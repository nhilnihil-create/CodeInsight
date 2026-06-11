#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;


void solve() {
	char a[50][50], b[50][50];
	int n, m;
	bool match = false;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
	    for(int j = 0; j < n; ++j) {
		cin >> a[i][j];
		}
	}
		for(int i = 0; i < m; ++i) {
	     	for(int j = 0; j < m; ++j) {
			cin >> b[i][j];
			}
		}
		for(int i = 0 ; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i + m - 1 >= n || j + m - 1 >= n) continue;
				bool exist = true;
				for(int lx = 0; lx < m; ++lx) {
					for(int ly = 0; ly < m; ++ly) {
						if(a[i + lx][j + ly] != b[lx][ly]) exist = false;
						}
					}
					if(exist) match = true;
				}
			}
			if(match) cout << "Yes" << endl;
			else cout << "No" << endl;
			return;
}
	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
