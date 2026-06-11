#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;
int p[100000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i], p[i]--;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i != p[i]) continue;
		if (i + 1 < N) swap(p[i], p[i + 1]);
		else swap(p[i], p[i - 1]);
		ans++;
	}
	cout << ans << endl;
}