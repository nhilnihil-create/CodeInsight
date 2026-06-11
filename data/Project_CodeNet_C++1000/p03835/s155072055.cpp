#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
//const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main() {
  ll K,S; cin>>K>>S;
  ll cnt=0;
  
  for(ll i=K; i>=0; i--){
    if(S-i<0) continue;
    if(S-i>2*K) break;

    for(ll j=i; j>=0; j--){
      ll x=S-i-j;
      if(x>j) break;
      if(x<0) continue;
      
      if(i==j&&i==x) cnt++;
      else if(i!=j&&i!=x&&j!=x) cnt+=6;
      else cnt+=3;
    }
  }
  cout<<cnt<<endl;
}