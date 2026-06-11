#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
const int INF = 1 << 25;
const LL MOD = 1000000007LL;
using namespace std;
typedef pair<int, int> P;
int A[100000];
int main() {
	int N, T;
	cin >> N >> T;
	rep(i, N) cin >> A[i];
	int max_d = 0;
	int min_A = A[0];
	for (int i = 1; i < N; i++) {
		if (A[i] > min_A) max_d = max(max_d, A[i] - min_A);
		min_A = min(min_A, A[i]);
	}
	min_A = A[0];
	int ans = 0;
	for (int i = 1; i < N; i++) {
		if (A[i] - min_A == max_d) ans++;
		min_A = min(min_A, A[i]);
	}
	cout << ans << endl;
}