#include<algorithm>
#include<cmath>
#include<complex>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<deque>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int a[50] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N, greater<int>());
	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += a[i];
	}
	cout << ans << endl;
}