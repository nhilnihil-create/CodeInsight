#include <bits/stdc++.h>

#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second

ll gcd(ll a, ll b){
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

using namespace std;


int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n; cin >> n;
   
   int ans = 0;
   while(n--){
      int l, r; cin >> l >> r;
      int diff = (r-l) + 1;
      ans += diff;
   }
   cout << ans;
   return 0;
}
