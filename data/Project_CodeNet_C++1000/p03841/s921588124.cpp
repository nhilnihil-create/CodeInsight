#include<bits/stdc++.h>
using namespace std;

int N;
int X[505],Cnt[505],Num[505],Ans[505*505];

int main(){
	int i,j,k;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&X[i]);
		Ans[X[i]]=i;
	}
	for(i=1,j=0;i<=N*N;i++)
		if(Ans[i])
			Num[++j]=Ans[i];
	for(i=1;i<=N;i++)
		Cnt[i]=i-1;
	for(i=1;i<=N*N;i++)
		if(!Ans[i])
			for(j=1;j<=N;j++)
				if(Cnt[Num[j]]){
					Cnt[Ans[i]=Num[j]]--;
					break;
				}
	for(i=1;i<=N;i++)
		Cnt[i]=N-i;
	for(i=N*N;i;i--)
		if(!Ans[i])
			for(j=N;j;j--)
				if(Cnt[Num[j]]){
					Cnt[Ans[i]=Num[j]]--;
					break;
				}
	for(i=1;i<=N;i++)
		for(j=1,k=0;j<=N*N;j++){
			k+=(Ans[j]==i);
			if(k==i){
				if(j^X[i]){
					puts("No");
					return 0;
				}
				break;
			}
		}
	puts("Yes");
	for(i=1;i<=N*N;i++)
		printf("%d ",Ans[i]);
	return 0;
}