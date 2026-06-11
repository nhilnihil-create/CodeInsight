#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
int n,m;
vector<int> g[100001];
int dis1[100001],dis2[100001];
int sum1,sum2;
void dfs1(int fa,int x){
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]!=fa){
			dis1[g[x][i]]=dis1[x]+1;
			dfs1(x,g[x][i]);
		}
	}
}
void dfs2(int fa,int x){
	for(int i=0;i<g[x].size();i++){
		if(g[x][i]!=fa){
			dis2[g[x][i]]=dis2[x]+1;
			dfs2(x,g[x][i]);
		}
	}
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
	dfs1(0,0);
	dfs2(m,m);
	sum1=sum2=0;
	for(int i=0;i<n;i++){
		if(dis1[i]<=dis2[i]) sum1++;
		else sum2++;
	}
	if(sum1>sum2) cout<<"Fennec"<<endl;
	else cout<<"Snuke"<<endl;
    return 0;
}