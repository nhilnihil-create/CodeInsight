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

   string n; cin >> n;
   string ans = "No";
   for(char i : n){
      if(i == '9'){
         ans = "Yes";
         break;
      }
   }
   cout << ans;
   return 0;
}
