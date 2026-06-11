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
int cnt[100010];
vector<int> gr[100010];
int L[100010];
int n;
int P[100010];
void dfs(int v){
	cnt[v]=1;
	REP(i,gr[v].size()){
		int u=gr[v][i];
		if(P[v]==u)continue;
		L[u]=L[v]+1;
		P[u]=v;
		dfs(gr[v][i]);
		cnt[v]+=cnt[u];
	}
}
int a[100010],b[100010];
int main(){
	cin>>n;
	REP(i,n-1){
		cin>>a[i]>>b[i];
		gr[a[i]].push_back(b[i]);
		gr[b[i]].push_back(a[i]);
	}
	dfs(1);
	int up=(L[n]-1)/2;
	int v=n;
	while(up--)v=P[v];
	if(cnt[v]>=n-cnt[v])cout<<"Snuke"<<endl;
	else cout<<"Fennec"<<endl;
	return 0;
}