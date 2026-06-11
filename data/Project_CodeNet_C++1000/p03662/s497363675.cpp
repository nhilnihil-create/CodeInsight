#include<bits/stdc++.h>
#define FORN(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=(c).end();i++)
#define ll long long
#define sz(s) s.size()
#define all(s) s.begin(),s.end()
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
int a[100010];
int b[100010];
vector<int> gr[100010];
vector<int> Root;
bool vis[100010];
int n;
bool flag=false;
void dfs(int x,int y){
	if(vis[x])return ;
	vis[x]=true;
	if(x==y){
		flag=true;
		return ;
	}
	REP(i,gr[x].size()){
		Root.push_back(gr[x][i]);
		dfs(gr[x][i],y);
		if(flag)return ;
		else if(Root.size())Root.erase(Root.begin()+Root.size()-1);
	}
	return ;
}
int answer=0,result=0;
void dfs2(int k,int x,int y,int z){
	if(vis[x])return ;
	vis[x]=true;
	answer+=(k==1);
	result+=(k==2);
	REP(i,gr[x].size()){
		if(x==y&&z==gr[x][i])continue;
		dfs2(k,gr[x][i],y,z); 
	}
} 
int main(){
	cin>>n;
	REP(i,n-1){
		cin>>a[i]>>b[i];
		gr[a[i]].push_back(b[i]);
		gr[b[i]].push_back(a[i]);
	}
	if(n==1){
		cout<<"Fennec"<<endl;
		return 0;
	}
	Root.push_back(1);
	dfs(1,n);
	memset(vis,false,sizeof(vis));
	if(Root.size()%2==1){
		dfs2(1,1,Root[Root.size()/2],Root[Root.size()/2+1]);
		dfs2(2,Root[Root.size()/2+1],n,Root[Root.size()/2]);
	}
	else{
		dfs2(1,1,Root[Root.size()/2-1],Root[Root.size()/2]);
		dfs2(2,Root[Root.size()/2],n,Root[Root.size()/2-1]);
	}
	if(answer>result){
		cout<<"Fennec"<<endl;
	}
	else{
		cout<<"Snuke"<<endl;
	}
	return 0;
}