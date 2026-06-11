#include<bits/stdc++.h>
/******************************************/
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define forn(i,a,n) for(int i=a;i<n;i++)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define sz(s) s.size()
#define all(s) s.begin(),s.end()
#define zero(x) memset(x,0,sizeof(x))
#define vii vector<pair<int,int> >;
#define mpis map<int,string>
#define mpii map<int,int>
#define mpsi map<string,int>
#define re return
/******************************************/
using namespace std;
int n,a,b;
vector<int> v[100000];
int step[2][100000];
void dfs(int fx,int d,int c){
	step[c][d]=step[c][fx]+1;
	for(int i=0;i<v[d].size();i++)
	if(v[d][i]!=fx)
	dfs(d,v[d][i],c);
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		a--,b--;
		v[a].pb(b);
		v[b].pb(a);
	}
	step[0][0]=-1;
	step[1][n-1]=-1;
	dfs(0,0,0);
	dfs(n-1,n-1,1);
	int black=0,white=0;
	for(int i=0;i<n;i++){
		if(step[0][i]<=step[1][i])
		black++;
		else
		white++;
	}
	if(black>white)
	cout<<"Fennec";
	else
	cout<<"Snuke";
	re 0;
}