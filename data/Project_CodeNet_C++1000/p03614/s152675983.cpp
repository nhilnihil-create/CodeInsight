#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<ll,ll>
#define vl vector<ll>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvl vector<vector<ll>>
#define print(n) cout<<n<<endl
const int M=100111;
const int mod=1000000007;
const int inf=1000000007;
const long long INF=1000000000000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};


int main(){
	int n,p,cnt=0;
	cin>>n;
	bool f=false;
	rep(i,0,n){
		cin>>p;
		if(!f&&p==i+1){cnt++;f=true;}
		else f=false;
	}
	print(cnt);
}