#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvl vector<vector<ll>>
#define print(n) cout<<n<<endl
const int M=100111;
const int inf=1000000007;
const long long INF=1000000000000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};


int main(){
	ll n,m,x,y;
	cin>>n>>m;
	ll tmp1=0,tmp2=0,ans=0;
	rep(i,1,n+1){
		cin>>x;
		tmp1=(tmp1+(2*i-n-1)*x)%inf;
	}
	rep(i,1,m+1){
		cin>>y;
		tmp2=(tmp2+(2*i-m-1)*y)%inf;
	}
	ans=tmp1*tmp2%inf;
	print(ans);
}