#include<bits/stdc++.h>
#define REP(i,b,e) for(int i=b; i<e; i++)

int main(){
	int k, t;
	scanf("%d %d", &k, &t);
	int ans = 0, h = (k+1)/2;
	REP(i, 0, t){
		int a;
		scanf("%d", &a);
		if(a>h){
			ans += 2*(a-h) - (k%2==0);
		}
	}
	printf("%d\n", ans);
	return 0;
}

