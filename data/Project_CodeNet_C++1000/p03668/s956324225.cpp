// luogu-judger-enable-o2
//Code by : Y-k-y
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#define ll long long
const int N=100010;
using namespace std;
inline int rnd(){
	int res=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
inline void wr(int x){
	if(x<0){putchar('-');x=-x;}if(x>9) wr(x/10);putchar(x%10+'0');
}
vector<int>vec[N];
int n,sg[N];
inline void dfs(int u,int f){
	sg[u]=0;
	for(int i=0;i<vec[u].size();i++){
		int v=vec[u][i];
		if(v==f)continue;
		dfs(v,u);
		sg[u]^=(sg[v]+1);
	}
}
int main(){
	cin>>n;int x,y;
	for(int i=1;i<n;i++){
		x=rnd();y=rnd();
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1,0);
	if(sg[1])puts("Alice");
	else puts("Bob");
	return 0;
}
