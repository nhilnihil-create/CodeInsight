#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
int head[101000],NUM_EDGE;
bool BOOK[101000];
long long DIS[101000];
struct edge
{
	int TO;
	int NEXT;
	int DIS;
}EDGE[201000];
void ADD(int FROM,int TO,int DIS)
{
	EDGE[++NUM_EDGE].NEXT=head[FROM];
	EDGE[NUM_EDGE].TO=TO;
	EDGE[NUM_EDGE].DIS=DIS;
	head[FROM]=NUM_EDGE;
}
int read()
{
	int x=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+(c-'0'); c=getchar();}
	return x*f;
}
void DFS(int X) {
	for (int i=head[X]; i; i=EDGE[i].NEXT)
	if (BOOK[EDGE[i].TO]==0) {
		BOOK[EDGE[i].TO]=1;
		DIS[EDGE[i].TO]=DIS[X]+EDGE[i].DIS;
		DFS(EDGE[i].TO);
	}
}
int N,Q,K,U,V,W,X[101000],Y[101000],INF=111199999,MIN;
int main()
{
	N=read();
	for (int i=1; i<=N-1; i++) {
		U=read(); V=read(); W=read();
		ADD(U,V,W); ADD(V,U,W);
	}Q=read(); K=read();
	BOOK[K]=1;
	DFS(K);		
	for (int i=1; i<=Q; i++) {
		X[i]=read(); Y[i]=read(); printf("%lld\n",DIS[X[i]]+DIS[Y[i]]);
	}
	return 0;
}
