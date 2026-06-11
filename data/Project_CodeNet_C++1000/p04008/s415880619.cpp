#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL A[2000];
	UL m[2000];
	
	void Solve() {
		UL N; cin >> N;
		UL K; cin >> K;
		UL ans = 0;
		vector<UL> A(N); rep(i, N) { cin >> A[i]; A[i]--; }
		if (A[0] != 0) ans++;
		A[0] = 0;
		vector<UL> iA(N);
		for (UL i = 1; i < N; i++) {
			iA[A[i]]++;
		}
		vector<UL> dp(N);
		queue<UL> q;
		for (UL i = 1; i < N; i++) if(iA[i] == 0) q.push(i);
		while (q.size()) {
			UL p = q.front(); q.pop();
			dp[p]++;
			UL nx = A[p];
			if (nx == 0) continue;
			if (dp[p] == K) {
				ans++;
				dp[p] = 0;
			}
			dp[nx] = max(dp[nx], dp[p]);
			iA[nx]--;
			if (iA[nx] == 0) q.push(nx);
		}
		cout << ans << endl;
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
