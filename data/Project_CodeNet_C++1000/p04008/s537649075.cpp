#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
vector<int>v[100100];
int n,m,siz[100100],Ans;
inline void dfs(int x,int fa){
	siz[x]=1;
	for(int i=0;i<v[x].size();i++)
	  if(v[x][i]!=fa){
	  	dfs(v[x][i],x);
	  	siz[x]=max(siz[x],siz[v[x][i]]+1);
	  }
	if(fa!=1&&siz[x]==m)siz[x]=0,Ans++;
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
      int x;
      scanf("%d",&x);
      if(i==1&&x!=1)Ans=1;
      if(i>1)v[x].push_back(i),v[i].push_back(x);
    }
    for(i=0;i<v[1].size();i++)dfs(v[1][i],1);
    printf("%d\n",Ans);
	return 0;
}