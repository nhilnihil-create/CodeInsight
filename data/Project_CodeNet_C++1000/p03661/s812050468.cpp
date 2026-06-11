#include <bits/stdc++.h>
using namespace std;

void solve(long long N, vector<long long> a){
	vector<long long> v(N + 1);
	for(int i = 0; i < N; ++i) {
		v[i + 1] = v[i] + a[i];
	}
	long long res = (long long)1e+18;
	for(int i = 1; i < N; ++i) {
		res = min(res, abs(v[i] - (v[N] - v[i])));
	}
	cout << res << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, a);
	return 0;
}

