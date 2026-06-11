#include <bits/stdc++.h>
 
#define N 100009
 
using namespace std;
 
int lvl[N],sub[N],n,pa[N];
vector<int> l[N];

void dfs(int ver,int par){
	pa[ver]=par;
	sub[ver]=1;
	for(auto it : l[ver]){
		if(it==par){
			continue ;
		}
		lvl[it]=lvl[ver]+1;
		dfs(it,ver);
		sub[ver]+=sub[it];
	}
	return ;
}

int main(){
	int i,j,t1,t2,t3,t4,lim,curr;
	bool yay=false;
	scanf("%d",&n);
	for(i=0;i<n-1;i++){
		scanf("%d %d",&t1,&t2);
		l[t1].push_back(t2);
		l[t2].push_back(t1);
	}
	lvl[1]=0;
	dfs(1,-1);
	lim=ceil(lvl[n]/2.0);
	if(lvl[n]%2==0){
		lim++;
	}
	curr=n;
	for(i=lvl[n]-lim;i>0;i--){
		curr=pa[curr];
	}
	t2=n-sub[curr];
	t3=sub[curr];
	if(t2>t3){
		yay=true;
	}
	if(yay){
		printf("Fennec\n");
	}
	else{
		printf("Snuke\n");
	}
	return 0;		
}