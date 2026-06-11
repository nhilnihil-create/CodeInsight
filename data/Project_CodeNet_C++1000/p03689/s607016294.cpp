#include<iostream>
#include<cstdio>
using namespace std;
long long maxn;
long long sum;
long long mp[510][510];
int main(){
	int H,W,h,w;
	scanf("%d%d%d%d",&H,&W,&h,&w);
	if(H % h == 0 && W % w == 0){
		printf("No");
		return 0;
	}
	else if(h == 1 && w == 1){
		printf("No");
		return 0;
	}
	maxn = (int)H*W / (h*w) + 100;
	//printf("Yes\n");
	for(int i = 1;i <= H;i ++){
		for(int j = 1;j <= W; j++){
			if(i % h == 0 && j % w == 0){
				mp[i][j] = - maxn*(h*w-1) - 1;
				//printf("%lld",- maxn*(h*w-1) - 1);
			}
			else{
				mp[i][j] = maxn;
				//printf("%lld",maxn);
			}
			sum += mp[i][j];
			//printf("\n");
		}
	}
	if(sum < 0){
		printf("No");
	}
	else{
		printf("Yes\n");
		for(int i = 1;i <= H;i ++){
			for(int j = 1;j <= W;j ++){
				printf("%lld ",mp[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}