#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int W, H; cin >> W >> H;
	int N; cin >> N;
	vector<int> x(N), y(N), a(N);
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> a[i];
	int left = 0, right = W, up = H, down = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] == 1) left = max(left, x[i]);
		else if(a[i] == 2) right = min(right, x[i]);
		else if(a[i] == 3) down = max(down, y[i]);
		else up = min(up, y[i]);
	}
	int ans = max(0,(right - left)) * max(0,(up - down));
	cout << ans << endl;
	return 0;
}