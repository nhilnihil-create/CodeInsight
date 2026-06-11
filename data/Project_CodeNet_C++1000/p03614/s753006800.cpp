#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
const int INF = 1 << 25;
const LL MOD = 1000000007LL;
using namespace std;
typedef pair<int, int> P;
int p[100000];
int main() {
	int N;
	cin >> N;
	rep(i, N) cin >> p[i], p[i]--;
	int ans = 0;
	for (int i = 0; i + 1 < N; i++) {
		if (p[i] == i) swap(p[i], p[i + 1]), ans++;
	}
	if (p[N - 1] == N - 1) ans++;
	cout << ans << endl;
}