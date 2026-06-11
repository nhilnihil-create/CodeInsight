#include <bits/stdc++.h>
// #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);i++)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}
const ll inf = 1LL<<60;

int main() {
  int n,k,high;cin>>n>>k;
  ll ans=inf;
  ll now=0;
  int color=0;

  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  for(int i=0;i<(1<<n);i++){
    high=a[0];
    color=1;
    now=0;
    for(int j=1;j<n;j++){
      if(1 & (i>>j)){
        if(a[j]<=high){
          now+=high-a[j]+1;
          high=high+1;
          color+=1;
        }else{
          color+=1;
          high=a[j];
        }
      }else{
        if(high<a[j]){
          high=a[j];
          color+=1;
        }
      }
    }
    if(k<=color){
      ans=min(ans,now);
    }
  }
  cout<<ans<<endl;
}
