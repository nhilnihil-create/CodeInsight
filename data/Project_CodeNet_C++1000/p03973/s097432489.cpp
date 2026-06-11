#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int N, i;
	scanf("%lld", &N);
	vector<int> A(N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	int now = 1, ans = A[0] - 1;
	for(i = 1; i < N; i++){
		if(A[i] == now + 1){
			now++;
		}
		else if(A[i] > now + 1){
			ans += (A[i] - 1) / (now + 1);
		}
//		printf("(now, ans)[%lld] = (%lld, %lld)\n", i, now, ans);
	}
	printf("%lld\n", ans);
	return 0;
}