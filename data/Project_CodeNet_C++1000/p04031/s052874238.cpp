#include <bits/stdc++.h>

#define ll long long
#define mk make_pair
#define pb push_back
#define ff first
#define sc second
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
   if(b == 0) return a;
   
   return gcd(b, a % b);
}

ll sum(int n){
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
using namespace std;


int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int n; cin >> n;
   vector<int> integ;
   int acc = 0;
   while(n--){
      int a; cin >> a;
      acc += a;
      integ.pb(a);
   }
   int d = integ.size();
   double y = (double) acc / d;
   y = round(y);
   int ans = 0;
   for(int i : integ){
      if(i != y){
         ans += pow(i-y, 2);
      }
   }

   cout << ans << endl;
   
   return 0;
}
