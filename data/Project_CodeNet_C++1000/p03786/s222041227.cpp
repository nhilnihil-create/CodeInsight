#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
using ll = long long;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  auto judge=[&](ll mid){
    ll now=a[mid];
    rep(i,n){
      if(i==mid)continue;
      if(a[i]<=now*2){
        now+=a[i];
      }
      else{
        return 0;
      }
    }
    return 1;
  };
  auto bs=[&](){
    ll l=-1,r=n;
    while(r-l>1){
      ll mid=(l+r)/2;
      if(judge(mid)){
        r=mid;
      }
      else{
        l=mid;
      }
    }
    return r;
  };
  cout<<n-bs()<<endl;
  return(0);
}
