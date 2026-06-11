#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long L, long long T, vector<long long> X, vector<long long> W){
	vector<long long> Y(N);
	for(int i = 0 ; i <= N-1 ; i++) {
		if (W[i] == 1) Y[i] = (X[i]+T)%L; else Y[i] = (X[i]-T)%L;
		if (Y[i] < 0) Y[i] += L;
	}
	long long sumc = 0;
	for(int i = 1 ; i <= N-1 ; i++) {
		if (W[0] != W[i]) {
			if (W[0] == 1 && X[i]-X[0] <= T*2) {
				sumc += 1+(T*2 - (X[i]-X[0]))/L;
			}
			if (W[0] == 2 && L-(X[i]-X[0]) <= T*2) {
				sumc += 1+(T*2 - (L-(X[i]-X[0])))/L;
			}
		}
	}
	long long z;
	// cout << sumc << "\n";
	if (W[0] == 1) {
		z = sumc%N;
	} else {
		z = (N-sumc%N)%N;
	}
	// cout << z << "\n";
	long long y = Y[0], n;
	sort(Y.begin(), Y.end());
  // n = distance(Y.begin(), upper_bound(Y.begin(), Y.end(), y))-1;
	if (W[0] == 1) {
		n = distance(Y.begin(), lower_bound(Y.begin(), Y.end(), y));
		if (Y[n] == Y[(n+1)%N]) z--;
	} else {
		n = distance(Y.begin(), upper_bound(Y.begin(), Y.end(), y))-1;
		if (Y[n] == Y[(n-1+N)%N]) z++;
	}
	// cout << n << "\n";
	// for (int i = 0; i < N; i++) cout << Y[i] << "\n";

	for(int i = n-z+N ; i <= n-z+N+N-1 ; i++) {
		cout << Y[i%N] << "\n";
	}

}

int main(){
	long long T;
	long long L;
	long long N;
	scanf("%lld",&N);
	vector<long long> X(N-1+1);
	vector<long long> W(N-1+1);
	scanf("%lld",&L);
	scanf("%lld",&T);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&X[i]);
		scanf("%lld",&W[i]);
	}
	solve(N, L, T, X, W);
	return 0;
}
