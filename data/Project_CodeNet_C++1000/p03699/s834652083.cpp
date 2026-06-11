#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	vi vec(n);
	int total=0;
	rep(i,0,n){
		int a; cin>>a;
		total+=a;
		vec[i]=a;
	}
	if(total%10!=0){
		cout<<total;
		return 0;
	}
	int ans=0;
	rep(i,0,n){
		int k=total-vec[i];
		if(k%10==0) k=0;
		ans=max(ans,k);
	}
	cout<<ans;
	
	return 0;
}