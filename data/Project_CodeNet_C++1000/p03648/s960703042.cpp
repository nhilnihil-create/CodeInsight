#include<bits/stdc++.h>
using namespace std;

long long int k;

#define MAX 50

long long int ans[MAX];

int main(){
	scanf("%lld", &k);
	long long int rest = k / MAX;
	for (int i = 0; i < MAX; i++){
		ans[i] += rest*MAX;
		ans[i] -= rest*(MAX-1);
		ans[i] += 49;
	}
	k %= MAX;
	for (int i = 0; i < k; i++){
		ans[i] += MAX;
		for (int j = 0; j < MAX; j++){
			if (i != j){
				ans[j]--;
			}
		}
	}
	puts("50");
	for (int i = 0; i < MAX; i++){
		if (i)printf(" ");
		printf("%lld", ans[i]);
	}
	puts("");
	return 0;
}