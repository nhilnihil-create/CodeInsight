#include <bits/stdc++.h>
using namespace std;
int n = 50;
long long ar[55];
int main(){
 	long long k;
	scanf("%lld", &k);
	for(int i = 0;i < n; ++i) ar[i] = i;
	long long plus = k / n;
	long long mod = k % n;
	for(int i = 0;i < n; ++i) ar[i] += plus;
	for(int i = 0;i < mod; ++i){
		for(int j = 0;j < n; ++j){
			if(i == j) ar[j] += n;
			else ar[j] -= 1;
		}
	}
	printf("50\n");
	for(int i = 0;i < n; ++i){
		printf("%lld%c", ar[i], (i == n - 1) ? '\n' : ' ');
	}
	return 0;
}

/*
5 0 1 2 3
4 5 0 1 2
3 4 5 0 1
2 3 4 5 0
1 2 3 4 5
*/