#include <bits/stdc++.h>
using namespace std;
#define int long long
#define p (int)(1e9 + 7)
#define inf (int)(1e9 + 1)

int MOD(int a){
	return (a %= p) >= 0 ? a : a + p;
}

signed main(){
	int N, i;
	scanf("%lld", &N);
	vector<int> T(N), A(N);
	for(i = 0; i < N; i++){
		scanf("%lld", &T[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	vector<int> m(N, 1), M(N, inf);
	m[0] = max(m[0], T[0]);
	M[0] = min(M[0], T[0]);
	for(i = 1; i < N; i++){
		if(T[i] > T[i - 1]){
			m[i] = max(m[i], T[i]);
			M[i] = min(M[i], T[i]);
		}
		else{
			M[i] = min(M[i], T[i]);
		}
	}
	m[N - 1] = max(m[N - 1], A[N - 1]);
	M[N - 1] = min(M[N - 1], A[N - 1]);
	for(i = N - 2; i >= 0; i--){
		if(A[i] > A[i + 1]){
			m[i] = max(m[i], A[i]);
			M[i] = min(M[i], A[i]);
		}
		else{
			M[i] = min(M[i], A[i]);
		}
	}
	int ans = 1;
	for(i = 0; i < N; i++){
		ans = MOD(ans * max(0ll, M[i] - m[i] + 1));
	}
	printf("%lld\n", ans);
	return 0;
}