#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7; bool fl[N];
int n,ans,len[N],val[N]; vector<int>v[N];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
inline void find(int u){
	fl[u]=1;
	for(int i=0;i<len[u];i++){
		int x=v[u][i]; if(fl[x]) continue; find(x),val[u]^=(val[x]+1);
	}
}
int main(){
	n=read(); int u,t;
	for(int i=1;i<n;i++) u=read(),t=read(),v[u].push_back(t),v[t].push_back(u),len[u]++,len[t]++; find(1);
	if(val[1]) puts("Alice"); else puts("Bob");
	return 0;
}