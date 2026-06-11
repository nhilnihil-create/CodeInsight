#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long INF = 1e18;

int main() {
	int n;
	cin >> n;
	vector<long long> a1(n), a2(n), a3(n);
	priority_queue<long long, vector<long long>, greater<long long>> pq1;
	priority_queue<long long> pq3;
	long long s1 = 0, s3 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
		pq1.push(a1[i]);
		s1 += a1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a2[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a3[i];
		pq3.push(a3[i]);
		s3 += a3[i];
	}
	vector<long long> aux1(n+1), aux2(n+1);
	aux1[0] = s1;
	for (int i = 0; i < n; i++) {
		pq1.push(a2[i]);
		s1 += a2[i];
		s1 -= pq1.top(); pq1.pop();
		aux1[i+1] = s1;
	}
	aux2[n] = s3;
	for (int i = 0; i < n; i++) {
		pq3.push(a2[n-1-i]);
		s3 += a2[n-1-i];
		s3 -= pq3.top(); pq3.pop();
		aux2[n-1-i] = s3;
	}
	long long ans = -INF;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, aux1[i] - aux2[i]);
	}
	cout << ans << endl;
	return 0;
}