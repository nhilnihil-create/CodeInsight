#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int a[100002]; 
int main() {
	int n;
	cin >> n;
	rep(i, n) {
		int x; cin >> x;
		if (x == 0) {
			a[0]++; a[1]++;
		} else {
			a[x-1]++; a[x]++; a[x+1]++;
		}
	}
	int ma = -1;
	rep(i, 100002) {
		ma = max(ma, a[i]);
	}
	cout << ma << endl;
	return 0;
}