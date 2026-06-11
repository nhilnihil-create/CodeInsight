#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll d[300][300];
int r[10];
int main()
{
	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 0; i < R; i++) {
		cin >> r[i];
		r[i]--;
	}
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			if (i != j)d[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		d[a][b] = c;
		d[b][a] = c;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	ll ans = INF;
	sort(r, r + R);
	do {
		ll sum = 0;
		for (int i = 0; i < R - 1; i++) {
			sum += d[r[i]][r[i + 1]];
		}
		ans = min(ans, sum);
	} while (next_permutation(r, r + R));
	cout << ans << endl;
}