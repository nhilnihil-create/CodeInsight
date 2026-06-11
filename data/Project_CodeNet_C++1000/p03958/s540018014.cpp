#include<bits/stdc++.h>

int main(){
	int k, t, ans = 0;
	scanf("%d %d", &k, &t);
	for(int i=0; i<t; i++){
		int a;
		scanf("%d", &a);
		ans = std::max(ans, (a-(k+1)/2)*2-1);
	}
	printf("%d\n", ans);
}
