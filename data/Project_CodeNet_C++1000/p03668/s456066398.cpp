#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int Next[220000],h[220000],v[220000],tot,sg[220000];
int n;
int add(int x,int y){
	tot++;
	Next[tot]=h[x];
	v[tot]=y;
	h[x]=tot;
}
int dfs(int x,int fa){
	for(int i=h[x];i;i=Next[i]){
		if(v[i]==fa)continue;
		dfs(v[i],x);
		sg[x]^=sg[v[i]];
	}
	if(x!=1)sg[x]++;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	if(sg[1])printf("Alice\n");
	else printf("Bob\n");
}