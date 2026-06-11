#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define ll long long int
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD=1e9+7;
 ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void solve(){
   ll n;
   cin >> n;
   map<int,int> mp;
   for(int i=0;i<n;i++){
      int a;
      cin >> a;
      mp[a]++;
   }
   if(n%2==1){
     if(mp[0]!=1){cout << 0;return;}
      for(int i=2;i<=n;i+=2){
          if(mp[i]!=2){cout << 0;return;}
      }
      cout << binpow(2LL,n/2);
   }
   else{
     for(int i=1;i<=n;i+=2){
       if(mp[i]!=2){cout << 0;return;}
     }
     cout << binpow(2LL,n/2);
   }
}


int main(){
  IOS
     solve();
}
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
