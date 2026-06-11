#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int fr[100002]; 
int main() {
	int n;
	cin >> n;
	rep(i, n) {
		int a; cin >> a;
		a--;
		fr[i] = a;
	}
	ll cnt = 0;
	rep(i, n) {
		int j = fr[i];
		if (fr[j] == i) cnt++;
	}
	cnt /= 2;
	cout << cnt << endl;
	return 0;
}