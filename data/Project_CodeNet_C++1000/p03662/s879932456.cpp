#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
int n,m;
vector<int> g[100001];
int cnt[100001];
int fct,frst;
vector<int> s;
void dfs(int fa,int x){
	cnt[x]=1;
	s.push_back(x);
	if(x==m){
		frst=s[(s.size()+1)/2];
	}
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]!=fa){
			dfs(x,g[x][i]);
			cnt[x]+=cnt[g[x][i]]; 
		}
	}
	s.pop_back();
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	m=n-1;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	dfs(0,0);
	fct=cnt[frst];
	bool win=(fct*2<n);
	if(win) cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
    return 0;
}