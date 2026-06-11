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
const int M=100111;
const int inf=1000000007;
const long long INF=1e18;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int ddx[8]={1,-1,0,0,1,-1,-1,1},ddy[8]={0,0,1,-1,1,-1,1,-1};

/*
vvl comb(int n, int r) {
	vvl v(n + 1,vl(n + 1, 0));
	for (int i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (int j = 1; j < v.size(); j++) {
		for (int k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v;
}
*/


int main() {
	map<P,int> m;
	int h,w,n,x,y;
	ll ans[10]={};
	cin>>h>>w>>n;
	rep(i,0,n){
		cin>>x>>y;
		rep(j,0,3)rep(k,0,3)
			m[make_pair(y-j,x-k)]++;
	}
	ans[0]=1ll*(h-2)*(w-2);
	for(auto it:m){
		int a=it.first.first;
		int b=it.first.second;
		int c=it.second;
		if(a>=1&&a+2<=w&&b>=1&&b+2<=h)ans[c]++,ans[0]--;
	}
	rep(i,0,10)print(ans[i]);
}