#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
bool isred[maxn]={false};
int ball_num[maxn];
int main(){
	isred[1]=true;
	fill(ball_num,ball_num+maxn,1);
	int N,M,x,y;
	scanf("%d%d",&N,&M);
	while(M--){
		scanf("%d%d",&x,&y);
		ball_num[x]--;ball_num[y]++;
		if(isred[x]==true)	isred[y]=true;
		if(ball_num[x]==0)	isred[x]=false;
	}
	int sum=0;
	for(int i=1;i<=N;i++){
		//printf("%d:%d %d\n",i,ball_num[i],isred[i]);
		if(isred[i]==true)	sum++;
	}
	printf("%d\n",sum);
	return 0;
}