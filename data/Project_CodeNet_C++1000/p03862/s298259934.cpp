#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define ll long long int
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD=1e9+7;

void solve(){
   ll n,x;
   cin >> n >> x;
   vector<ll> v(n);
   for(int i=0;i<n;i++)cin >> v[i];

   ll ans=0;
   if(v[0] > x)ans+=(v[0]-x),v[0]-=(v[0]-x);
   for(int i=0;i<n-1;i++){
      ll k = max(0LL,v[i]+v[i+1]-x);
      ans += k;
      v[i+1]-=k;
   }
   cout << ans;
}


int main(){
  IOS
     solve();
}
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// calculating after processing
