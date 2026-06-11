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
	int n,a[M],t;
	cin>>n>>t;
	int lmin[M],rmax[M]={};
	rep(i,0,M)lmin[i]=inf;
	rep(i,0,n)cin>>a[i];
	//1-index
	rep(i,1,n+1)lmin[i]=min(lmin[i-1],a[i-1]);
	for(int i=n+1;i>0;i--)rmax[i]=max(rmax[i-1],a[i-1]);
	int tmp_div=0,div=0,cnt_min=0,cnt_max=0;
	rep(i,1,n+1){
		int tmp=rmax[i]-lmin[i];
		tmp_div=max(tmp_div,tmp);
		if(tmp_div==tmp){
			if(div<=tmp_div){
				if(div<tmp_div){
					cnt_max=0;
					cnt_min=0;
				}
				div=tmp_div;
				cnt_max++;
				cnt_min++;
			}
		}
	}
	print(min(cnt_min,cnt_max));

}