#include <bits/stdc++.h>
using namespace std;


#define int long long 


const int N = 1e5 + 7;

int h[N];


int chk(int x, int a, int b, int n) {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		int y = h[i] - b * x;
		if(y > 0) {
			cnt += (y - 1) / a + 1;
		}
	}
	return cnt <= x;
}

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a, b; cin >> n >> a >> b;
	for(int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	int l = 1, r = *max_element(h + 1, h + n + 1);

	while(l < r) {
		int mid = (l + r) >> 1;
		if(chk(mid, a - b, b, n)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;

}