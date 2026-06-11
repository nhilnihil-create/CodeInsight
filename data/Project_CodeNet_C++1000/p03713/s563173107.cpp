#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main() {
  ll h,w;
  cin>>h>>w;
  ll ans=1e18;
  for (int i=1; i<=h; i++) {
    ll s1=i*w;
    ll s2=(h-i)*(w/2);
    ll s3=h*w-s1-s2;
    ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
  }
  ans=min(ans,((h+3-1)/3)*w-(h/3)*w);
  swap(h,w);
  for (int i=1; i<=h; i++) {
    ll s1=i*w;
    ll s2=(h-i)*(w/2);
    ll s3=h*w-s1-s2;
    ans=min(ans,max({s1,s2,s3})-min({s1,s2,s3}));
  }
  ans=min(ans,((h+3-1)/3)*w-(h/3)*w);
  cout<<ans<<endl;
  return 0;
}

