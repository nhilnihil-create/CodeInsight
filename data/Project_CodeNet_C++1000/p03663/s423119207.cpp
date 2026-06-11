#include <bits/stdc++.h>

using namespace std;

char ans[10];
int Getlen(){
	int x = 10;
	for(int i = 1; i <= 9; ++i){
		printf("? %d\n",x);
		fflush(stdout);
		scanf("%s",ans);
		if(ans[0] == 'N')return i;
		x *= 10;
	}
	x = 9;
	for(int i = 1; i <= 9; ++i){
		printf("? %d\n",x);
		fflush(stdout);
		scanf("%s",ans);
		if(ans[0] == 'Y')return i;
		x *= 10;x += 9;
	}return 10;
}
int main(){
	int len = Getlen();
	//printf("%d\n",len);
	if(len == 10){
		printf("! %d\n",1000000000);
		fflush(stdout);
		return 0;
	}
	int Ans = 0;
	for(int bit = 1; bit < len; ++bit){
		int l = 0,r = 9,re = 0;
		Ans *= 10;
		while(l <= r){
			int mid = l + r >> 1;
			printf("? %d\n",Ans + mid);
			fflush(stdout);
			scanf("%s",ans);
			if(ans[0] == 'Y')re = mid,l = mid + 1;
			else r = mid - 1;
		}
		Ans += re;
	}
	Ans *= 10;
	for(int i = (len == 1); i <= 9; ++i){
		printf("? %lld\n",10LL * (Ans + i));
		fflush(stdout);
		scanf("%s",ans);
		if(ans[0] == 'Y'){
			printf("! %d\n",Ans + i);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}
