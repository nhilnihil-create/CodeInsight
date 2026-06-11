#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define print(n) cout<<n<<endl
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define vvl vector<vector<ll>>
#define vvi vector<vector<int>>
const int M=200111;
const int inf=1000000007;
const long long INF=1e18;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};

int n,a,b,cnt=0;
int flag[M];
int dist1[M]={},distn[M]={};
vi g[M];

void __dist(int node,int y[]){
	flag[node]=true;
	for(auto x:g[node])
		if(!flag[x]){
			y[x]=(y[node]+1);
			__dist(x,y);
		}
}

int main(){
	cin>>n;
	rep(i,0,n-1){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rep(i,0,n+1)flag[i]=false;
	__dist(1,dist1);
	rep(i,0,n+1)flag[i]=false;
	__dist(n,distn);
	int X=0,Y=0;
	rep(i,1,n+1){
		if(dist1[i]<=distn[i])X++;
		else Y++;
	}
	if(X>Y)print("Fennec");
	else print("Snuke");
}