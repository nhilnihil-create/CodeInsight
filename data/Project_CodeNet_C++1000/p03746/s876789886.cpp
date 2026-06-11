#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	static int n,m;
	static int a[100010],b[100010];
	scanf("%d%d",&n,&m);
	rep1(i,m){
		scanf("%d%d",&a[i],&b[i]);
	}
	
	static set<int> G[100010];
	static set<int> _G[100010];
	rep1(i,m){
		G[a[i]].insert(b[i]);
		G[b[i]].insert(a[i]);
	}
	rep1(i,n)_G[i] = G[i];
	vector<int> ret;
	ret.pb(1);
	int loc = 1;
	for(int v: _G[loc]){
		G[v].erase(loc);
	}
	while(!G[loc].empty()){
		loc = *G[loc].begin();
		ret.pb(loc);
		for(int v: _G[loc]){
			G[v].erase(loc);
		}
	}
	rev(ret);
	loc = 1;
	while(!G[loc].empty()){
		loc = *G[loc].begin();
		ret.pb(loc);
		for(int v: _G[loc]){
			G[v].erase(loc);
		}
	}
	cout << ret.size() << endl;
	rep(i,ret.size()){
		printf("%d%c",ret[i],i+1==ret.size()?'\n':' ');
	}
}