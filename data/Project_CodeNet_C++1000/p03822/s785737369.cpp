#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename tn> void read(tn &a){
	tn x=0,f=1; char c=' ';
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	a=x*f;
}
int n,a[101000],dep[101000];
vector<int> e[101000];
void dfs(int x){
	vector<int> p;
	for(int v:e[x]){
		dfs(v);
		p.push_back(dep[v]);
	}
	int ans=0;
	sort(p.begin(),p.end(),greater<int>());
	for(int i=0;i<p.size();i++)
		ans=max(ans,i+1+p[i]);
	dep[x]=ans;
}
int main(){
	read(n);
	for(int i=2;i<=n;i++)
		read(a[i]),e[a[i]].push_back(i);
	dfs(1);
	cout<<dep[1]<<'\n';
	return 0;
}
