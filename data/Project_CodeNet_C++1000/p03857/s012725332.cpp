#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int N,K,L,u,v,cnt[202018];
long long bb[4][202018];

int zbb(int i,int c)
{
	return bb[c][i]==i?i:bb[c][i]=zbb(bb[c][i],c);
}

int main()
{
	scanf("%d %d %d",&N,&K,&L);
	for(int i=1;i<=N;i++)
		bb[0][i]=i,bb[1][i]=i,bb[2][i]=i,bb[3][i]=i;
		
	for(int i=1;i<=K;i++)
	{
		scanf("%d %d",&u,&v);
		int p=zbb(u,0),q=zbb(v,0);
		if(p!=q) bb[0][q]=p;
	}
	
	for(int i=1;i<=L;i++)
	{
		scanf("%d %d",&u,&v);
		int p=zbb(u,1),q=zbb(v,1);
		if(p!=q) bb[1][q]=p;
	}
	
	for(int i=1;i<=N;i++)
		bb[2][i]=bb[3][i]=zbb(bb[0][i],0)+1LL*zbb(bb[1][i],1)*(N+1);
	
	sort(bb[3]+1,bb[3]+1+N);
	for(int i=1;i<=N;i++)
	{
		int pos=lower_bound(bb[3]+1,bb[3]+1+N,bb[2][i])-bb[3];
		cnt[pos]++;
	}
	for(int i=1;i<=N;i++)
	{
		int pos=lower_bound(bb[3]+1,bb[3]+1+N,bb[2][i])-bb[3];
		cout<<cnt[pos]<<' ';
	}
}