#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,cnt[N],x[N],a[N*N],c[N],vis[N];
int S1[N*N],T1,S2[N*N],T2,S3[N*N],T3;
bool cmp(int p,int q){ return x[p]<x[q];}
void GG(){ printf("No"); exit(0);}
int main()
{
	int i,j,p=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]),a[x[i]]=c[i]=i,cnt[i]=i-1;
	sort(c+1,c+n+1,cmp);
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++) S1[++T1]=i;
	for(i=1;i<=n*n;i++){
		while(T1&&vis[S1[T1]]) T1--;
		if(i==x[c[p]]){
			vis[c[p]]=1;
			while(cnt[c[p]]){
				while(T2&&vis[a[S2[T2]]]) T2--;
				if(!T2) GG();
				S1[++T1]=a[S2[T2]],cnt[S1[T1]]++;
				a[S2[T2]]=c[p],cnt[c[p]]--;
			  }
			for(j=1;j<=n-c[p];j++) S3[++T3]=c[p];
			p++;
		  }
		else{
			if(T1) S2[++T2]=i,cnt[S1[T1]]--,a[i]=S1[T1--];
			else{ if(!T3) GG(); a[i]=S3[T3--];}
		  }
	  }
	printf("Yes\n");
	for(i=1;i<=n*n;i++)
		printf("%d ",a[i]);
	return 0;
}
