#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
	ll N,K;
  	cin>>N>>K;
  	ll num[100001];
  	rep(i,100001) num[i]=0;
  
  	ll sum=0;
  	rep(i,N){
     	 ll a,b;
      	 cin>>a>>b;
      	 num[a]+=b;
    }
  
  	for(int i=1;i<100001;i++){
     	 sum+=num[i];
      	 if(sum>=K){
          	cout<<i<<endl;
           	break;
         }
    }
    
  	
  	
}