#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<int>a(N);
	rep(i, N)cin >> a[i];
	int h = 0, w = 0;
	vector<vector<int>>ans(H, vector<int>(W));
	bool flag = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < a[i]; j++) {
			ans[h][w] = i + 1;
			if (flag) {
				w++;
				if (w == W) {
					h++;
					w--;
					flag = !flag;
				}
			}
			else {
				w--;
				if (w == -1) {
					h++;
					w++;
					flag = !flag;
				}
			}
		}
	}
	rep(i, H) {
		rep(j, W) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}