#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define s(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
int main(){
  int n,m;
  cin >> n>>m;
  ll a[n];
  rep(i,n)cin>>a[i];
  ll ans =100000000000;
  for(int bit =0;bit<(1<<n);bit++){
    int count =0;
    ll nowprice =0;
    ll nowhigh=0;
    rep(i,n){
      
      if(bit&(1<<i)){
        if(nowhigh>=a[i]){
          nowprice+=nowhigh-a[i]+1;
          nowhigh++;
        }
        else nowhigh=a[i];
        count++;
      }
      else{ if(nowhigh<a[i]){
        nowhigh=max(nowhigh,a[i]);
        count++;}
    }
    if(count>=m)ans=min(ans,nowprice);

  }
  
}cout<<ans<<endl;
}