/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int col[100005];
vector<int> v[100005];
int n,m;
int __d,_col;
int use[100005];
int _v[100005],d[100005],c[100005];
inline void dfs(int x,int d){
	if(use[x]>=d) return;
	if(!col[x]) col[x]=_col;
	use[x]=d;
	for(int i=0;i<v[x].size();i++){
		int e=v[x][i];
		if(d) dfs(e,d-1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int i,j,q;
	cin>>n>>m;
    int x,y,z;
    for(i=1;i<=m;++i){
    	cin>>x>>y;
    	v[x].push_back(y);
    	v[y].push_back(x);
	}
	cin>>q;
	memset(use,-1,sizeof(use));
	for(j=1;j<=q;++j) cin>>_v[j]>>d[j]>>c[j];
	for(i=q;i;--i){
		_col=c[i];
		dfs(_v[i],d[i]);
	}
	for(i=1;i<=n;++i) cout<<col[i]<<endl;
	
	return 0;
}
