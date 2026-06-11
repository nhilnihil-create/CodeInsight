#include <bits/stdc++.h>

using namespace std;

int i,j;
long long k,ans[55];

int main(){
	scanf("%lld", &k);
	
	long long t = k / 50;
	k = k % 50;
	
	for(i = 0; i < 50; i++)
	ans[i] = i + t;
	
	for(i = 0; i < k; i++){
		for(j = 0; j < 50; j++){
			if(i == j)
			ans[j] += 50LL;
			else
			ans[j]--;
		}
	}
	
	printf("%d\n", 50);
	
	for(i = 0; i < 50; i++){
		if(i == 0)
		printf("%lld", ans[i]);
		else
		printf(" %lld", ans[i]);
	}
	printf("\n");
}
