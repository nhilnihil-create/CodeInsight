#include <bits/stdc++.h>

using namespace std;

#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define ull unsigned long long int

const int INF = 1e9 + 7;
const int N = 1e5+5;


int main() {

	IO;

	int n;
	cin >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	int m;
	cin >> m;
	
	for (int j = 0; j < m; ++j) {
		int pos, x, ans = 0;
		cin >> pos >> x;
		
		for (int i = 0; i < n; ++i) {
			if ( pos-1 == i) ans += x;
			else ans += a[i];
		}
		cout << ans << endl;
	}
	
}
