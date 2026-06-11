#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 103;
int n, cnt[N], k;
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i <= n;i ++){
		int x; scanf("%d", &x); ++ cnt[x]; k = max(k, x);
	}
	if(k & 1){
		for(Rint i = k + 1 >> 1;i <= k;i ++){
			if(cnt[i] < 2){puts("Impossible"); return 0;}
			cnt[i] -= 2;
		}
		for(Rint i = 0;i <= (k + 1 >> 1);i ++)
			if(cnt[i]){puts("Impossible"); return 0;}
	} else {
		if(!cnt[k >> 1]){puts("Impossible"); return 0;}
		-- cnt[k >> 1];
		for(Rint i = (k >> 1) + 1;i <= k;i ++){
			if(cnt[i] < 2){puts("Impossible"); return 0;}
			cnt[i] -= 2;
		}
		for(Rint i = 0;i <= (k >> 1);i ++)
			if(cnt[i]){puts("Impossible"); return 0;}
	}
	puts("Possible");
}