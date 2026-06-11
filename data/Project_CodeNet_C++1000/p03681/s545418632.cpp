#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	ll N,M;
  	cin>>N>>M;
  	ll mod=1;
  
  	rep(i,N) mod=mod*(i+1)%MOD;
  	rep(j,M) mod=mod*(j+1)%MOD;
  	if(M==N) mod=mod*2%MOD;
  	if(abs(M-N)>=2) mod=0;
  	cout<<mod<<endl;
}
