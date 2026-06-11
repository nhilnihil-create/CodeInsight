#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
char pixel[101];
int main() {
	int h, w;
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> pixel[j];
			cout << pixel[j];
		}
		cout << endl;
		rep(j, w) cout << pixel[j];
		cout << endl;
	}
	return 0;
}