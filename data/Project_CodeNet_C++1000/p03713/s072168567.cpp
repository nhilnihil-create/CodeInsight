#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const ll INF = 1e18;
const int MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
 
int main() {
  ll h,w;
  cin >> h >> w;
  ll ans = INF;
  ll res,s1,s2,s3;
  for(ll i=1;i<h;i++){
     s1 = w*i;
    if(w%2 == 0){
      s2 = (h-i)*(w/2);
      res = abs(s1-s2);
    }else if((h-i)%2 == 0){
      s2 = w*((h-i)/2);
      res = abs(s1-s2);
    }else{
      if(w < h-i){
        s2 = w*((h-i)/2);
        s3 = w*(((h-i)/2)+1);
        res = max(s1,s3)-min(s1,s2);
      }else{
        s2 = (h-i)*(w/2);
        s3 = (h-i)*((w/2)+1);
        res = max(s1,s3)-min(s1,s2);
      }
    }
    ans = min(ans,res);
  }
  for(ll i=1;i<w;i++){
    ll s1 = h*i;
    if(h%2 == 0){
      ll s2 = (w-i)*(h/2);
      res = abs(s1-s2);
    }else if((w-i)%2 == 0){
      ll s2 = h*((w-i)/2);
      res = abs(s1-s2);
    }else{
      if(h < w-i){
        ll s2 = h*((w-i)/2);
        ll s3 = h*(((w-i)/2)+1);
        res = max(s1,s3)-min(s1,s2);
      }else{
        ll s2 = (w-i)*(h/2);
        ll s3 = (w-i)*((h/2)+1);
        res = max(s1,s3)-min(s1,s2);
      }
    }
    ans = min(ans,res);
  }
  cout << ans << endl;    
    
  return 0;
}