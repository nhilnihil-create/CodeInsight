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

const long double EPS = 0.0000001;


	static int ret = 0;
	static int N,K;
	static int a[100010];

vector<int> ch[100010];
int add[100010],dist[100010];
void dfs(int v){
	//cout << "v = " << v << endl;
	add[v] = 0;
	dist[v] = 0;
	for(int i = 0 ; i < ch[v].size() ; i ++){
		int u = ch[v][i];
		dfs(u);
		add[v] += add[u];
		dist[v] = max( dist[v], dist[u]+1 );
	}
	if(dist[v] >= K-1 && a[v] != 1){
		add[v] ++;
		dist[v] = -1;
	}
	//cout << v << ":" << add[v] << " " << dist[v] << endl;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i = 1 ; i <= N ; i ++){
		scanf("%d",&a[i]);
	}
	
	if(a[1] != 1){
		ret ++;
		a[1] = 1;
	}
	for(int i = 2 ; i <= N ; i++){
		ch[a[i]].pb(i);
	}
	
	dfs(1);
	cout << add[1]+ret << endl;
}
