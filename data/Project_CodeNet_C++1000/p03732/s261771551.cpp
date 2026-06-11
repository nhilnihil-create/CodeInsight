#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define print(A,x,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i]x;}cout<<endl;
#define pprint(A,y,m,n) rep(j,0,m){print(A[j],y,n);}
const long mod=1e9+7;
const int size=2e5;
const int inf=1e9;
int main(){
	int N;long W;cin>>N>>W;
	long w,s;int v;
	vector<int> a[4];
	rep(i,0,4) a[i].push_back(0);
	rep(i,0,N){
		cin>>w>>v;
		if(i == 0) s = w;
		a[w - s].push_back(v);
	}
	rep(i,0,4){
		sort(a[i].begin() + 1 , a[i].end() , greater<int>());
		rep(j,1,a[i].size()) a[i][j] += a[i][j-1];
	}
	int ans = 0;
	rep(i,0,a[0].size())rep(j,0,a[1].size())rep(k,0,a[2].size())rep(l,0,a[3].size()){
		if(i*s + j*(s+1) + k*(s+2) + l*(s+3) <= W){
			ans = max(ans , a[0][i] + a[1][j] + a[2][k] + a[3][l]);
		}
	}cout<<ans<<endl;
}