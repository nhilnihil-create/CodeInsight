#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
const long long int mod=1000000007;
int main(void) {
	long long int i,N,go=1,ans=1;
	long long int x[100005];
	scanf("%lld", &N);
	for (i = 0; i < N; i++) {
		scanf("%lld", &x[i]);
	}
	//i番目がゴールする必要十分条件
	//i-1までのjについて2j+1<=x[j]
	//2i<=x[i]
	for (i = 0; i < N; i++) {
		while (go<N&&(2*(go-1-i)<x[go-1])&& (2 * (go- i)<=x[go])) {
			go++;
		}

		ans *= go - i;
		ans %= mod;
	}
	printf("%lld", ans);
	return 0;
}