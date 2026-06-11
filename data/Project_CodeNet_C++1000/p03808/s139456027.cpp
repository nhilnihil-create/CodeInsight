#include<bits/stdc++.h>
using namespace std;

int N , A[100003];

int main(){
	cin >> N; long long sum = 0; for(int i = 1 ; i <= N ; ++i){cin >> A[i]; sum += A[i];}
	long long num = N * (N + 1ll) / 2; if(sum % num){puts("NO"); return 0;}
	sum /= num; A[N + 1] = A[1]; long long cnt = 0;
	for(int i = 2 ; i <= N + 1 ; ++i){
		if(A[i - 1] + sum < A[i] || (A[i - 1] + sum - A[i]) % N){puts("NO"); return 0;}
		cnt += (A[i - 1] + sum - A[i]) / N;
	}
	puts(sum == cnt ? "YES" : "NO");
	return 0;
}
