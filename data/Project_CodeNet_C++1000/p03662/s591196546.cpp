#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n)  RFOR(i,0,n)
#define VSORT(v) sort(v.begin(), v.end())
#define DVSORT(v) sort(v.begin(), v.end(),greater<int>())
#define SORT(v, n) sort(v, v+n)
#define DSORT(v,n) sort(v, v+n,greater<int>())
#define vi vector<int>
#define pb push_back
 
template <class T> void chmin(T&a,const T&b) { a = min(a,b); }
template <class T> void chmax(T&a,const T&b) { a = max(a,b); }
 
void print(){cout<<endl;}
template <class Head, class... Tail>
void print(Head&& h,Tail&&... t){ 
	if(sizeof...(t)==0)
		cout<<h;
	else
		cout<<h<<' ';
	print(move(t)...);
}
 
const double EPS =1e-9;
const long INF =2147483647;//32bit 2*1e+9
const long MOD =1e+9+7;
#define PI 3.14159265258979
#define P pair<int,int>
#define PPi pair<P,int>
 
int dy[]={0, 0, 1, -1, 1, 1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1, -1, 1};

struct vertex{ vector<int> edge;};
vertex G[100001];
int N,d1[100001],dN[100001];

void dfsN(int p){	
	REP(i,G[p].edge.size()){
		int tem=G[p].edge[i];
		if(tem!=1&&dN[tem]==INF){
			dN[tem]=dN[p]+1;
			dfsN(tem);
		}
	}
	return;
}

void dfs1(int p){
	REP(i,G[p].edge.size()){
		int tem=G[p].edge[i];
		if(tem!=N&&d1[tem]==INF){
			d1[tem]=d1[p]+1;
			dfs1(tem);
		}
	}
	return;
}
int main(void){
	int a,b,result=0;
	REP(i,100001){
		d1[i]=INF;
		dN[i]=INF;
	}
	cin>>N;
	REP(i,N-1){
		cin>>a>>b;
		G[a].edge.pb(b); 
		G[b].edge.pb(a);
	}
	d1[1]=0; dN[N]=0;
	dfs1(1); 
	dfsN(N);
	FOR(i,2,N){
		if(d1[i]<=dN[i]) result++;
		else result--;
	}

	string S=result>0 ? "Fennec" : "Snuke";

	print(S);
	return 0;
}


