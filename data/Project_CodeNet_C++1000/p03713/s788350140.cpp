#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

ll tmin(ll a,ll b,ll c){
  return min(min(a,b),c);
}

ll tmax(ll a,ll b,ll c){
  return max(max(a,b),c);
}

int main(){
  ll h,w;
  cin >> h >> w;
  ll ans = h*w;
  rep1(i,h-1){//iで分割
    ll s1 = i*w;
    //縦割
    ll s2 = (h-i)*(w/2);
    ll s3 = h*w - s1 - s2;
    ans = min(ans,tmax(s1,s2,s3)-tmin(s1,s2,s3));
    //横割
    ll s4 = ((h-i)/2)*w;
    ll s5 = h*w - s1 - s4;
    ans = min(ans,tmax(s1,s4,s5)-tmin(s1,s4,s5));
  }
  swap(h,w);
  rep1(i,h-1){//iで分割
    ll s1 = i*w;
    //縦割
    ll s2 = (h-i)*(w/2);
    ll s3 = h*w - s1 - s2;
    ans = min(ans,tmax(s1,s2,s3)-tmin(s1,s2,s3));
    //横割
    ll s4 = ((h-i)/2)*w;
    ll s5 = h*w - s1 - s4;
    ans = min(ans,tmax(s1,s4,s5)-tmin(s1,s4,s5));
  }
  cout << ans << endl;
}