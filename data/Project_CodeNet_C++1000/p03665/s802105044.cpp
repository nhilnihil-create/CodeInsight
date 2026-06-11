#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
  int n ,p;
  cin >> n >> p ;
  vector<int>a(n);
  rep(i,n) cin>>a[i];
  
  int sum=0;
  rep(i,n){
    if(a[i]%2==1) sum++;
  }
  ll ans=pow(2,n);
  if(sum==0 && p==0) cout<<ans;
  if(sum==0 && p==1) cout<<0;
  if(sum!=0) cout<<ans/2;
  return 0;
}
