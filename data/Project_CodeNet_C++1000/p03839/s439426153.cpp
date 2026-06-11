#include<bits/stdc++.h>

using namespace std;

int main(){
	long long ans = 0;
	int N, K; cin >> N >> K;
	vector<long long> a(N), S1(N+1, 0), S2(N+1, 0);
	for(int i = 0; i < N; ++i){
		cin >> a[i];
		S1[i+1] = S1[i] + a[i];
		S2[i+1] = S2[i] + max(0LL, a[i]);
	}
	for(int i = 0; i + K <= N; ++i){
		int left = i, right = i + K;
		long long res = (S2[left] - S2[0]) + max(0LL, S1[right] - S1[left]) + (S2[N] - S2[right]);
		ans = max(ans, res);
	}
	cout << ans << endl;
}