#include <bits/stdc++.h>
typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using namespace std;

//const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

int main() {
   ll k,n,ans=1000000000000;
 
   cin>>n>>k;
   vll a(n);
   rep(i,n)cin>>a.at(i);
   
   for (int tmp = 0; tmp < (1 << (n-1)); tmp++) {
    bitset<14> s(tmp);  
    
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
      if (s.test(i)) {
        sum ++;
      }
    }
    if(sum>=k-1){
        
        ll h=a.at(0);
        ll money=0;
        
        rep(i,n-1){
            if(s.test(i)){
                if(h+1<=a.at(i+1)){
                    h=a.at(i+1);
                }else{
                    money+=(h+1-a.at(i+1));
                    h++;
                }
            }
            h=max(h,a.at(i+1));
        }
        ans=min(ans,money);
    }
   
  }
  if(k==1)cout<<0<<endl;
  else cout<<ans<<endl;

}

