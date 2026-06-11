#include <bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<lint, lint> P;

signed main(){
	lint N, sum_before = 0, sum_after = 0; cin >> N;
	vector<lint> a(3 * N);
	for(int i = 0; i < a.size(); i++) cin >> a[i];
	priority_queue<lint>  que_after;
	priority_queue<lint, vector<lint>, greater<lint> > que_before;
	vector<lint> before(N + 1, 0), after(N + 1, 0);

	for(int i = 0; i < N; i++) que_before.push(a[i]), sum_before += a[i];
	before[0] = sum_before;
	for(int x = 0; x < N; x++){
		que_before.push(a[N + x]); sum_before += a[N + x];
		sum_before -= que_before.top(); que_before.pop();
		before[x + 1] = sum_before;
	}

	for(int i = 2 * N; i < 3 * N; i++) que_after.push(a[i]), sum_after += a[i];
	after[0] = sum_after;
	for(int x = 0; x < N; x++){
		que_after.push(a[2 * N - x - 1]); sum_after += a[2 * N - x - 1];
		sum_after -= que_after.top(); que_after.pop();
		after[x + 1] = sum_after;
	}
	lint ans = -1e18;
	for(int i = 0; i <= N; i++) ans = max(ans, before[i] - after[N - i]);
	cout << ans << endl;
}