#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=(c).end();i++)
#define ll long long
#define sz(s) s.size()
#define all(s) s.begin(),s.end()
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
using namespace std;
int n;
vector<int> gr[100010];
int cnt[100010];
int frst;
vector<int> Root;
void dfs(int x,int y){
	cnt[x]=1;
	Root.push_back(x);
	if(x==n){
		frst=Root[(Root.size()+1)/2];
	}
	REP(i,gr[x].size()){
		if(gr[x][i]==y)continue;
		dfs(gr[x][i],x);
		cnt[x]+=cnt[gr[x][i]];
	}
	Root.erase(Root.begin()+Root.size()-1);
}
int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	frst=-1;
	dfs(1,1);
	if(cnt[frst]*2<n){
		cout<<"Fennec"<<endl;
	}
	else{
		cout<<"Snuke"<<endl;
	}
	return 0;
}