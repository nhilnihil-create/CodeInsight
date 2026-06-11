#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  ll ans=1;
  rep(i,1,n+1){
    ans=ans*i%mod;
  }
  cout<<ans<<endl;
}