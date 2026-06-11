#include<bits/stdc++.h>
using namespace std;
inline void ri(int &x){
	x=0; static char c; bool t=0;
	while(c=getchar(),c<'0'||c>'9') if(c=='-') t=1; else t=0;
	do x=x*10+c-'0'; while(c=getchar(),c>='0'&&c<='9');
	if(t) x=-x;
}
const int N=200024;
vector<int> Q[N];
int sg[N];
void dfs(int fa,int x){
	int i,l=Q[x].size(),ne;
	for(i=0;i<l;++i){
		ne=Q[x][i];
		if(ne==fa) continue;
		dfs(x,ne);
		sg[x]^=sg[ne]+1;
	}
}
int main(){
	int i,n,x,y; ri(n);
	for(i=1;i<n;++i){
		ri(x); ri(y);
		Q[x].push_back(y);
		Q[y].push_back(x);
	}
	dfs(-1,1);
	if(sg[1]==0) puts("Bob");
	else puts("Alice");
	return 0;
}