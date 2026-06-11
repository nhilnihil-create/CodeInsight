#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const ll mod=1e9+7;

int main(){
   ll n;
   string s;
   cin >> n;
   map<int,int> cnt;
   rep(i,n){
      int x;
      cin >> x;
      cnt[x]++;
   }
   ll ans=1LL;
   bool f=true;
   if (n%2==1){
      if (cnt[0]!= 1) f=false;
      for (int i = 0;i < n/2;i++){
         int id=2;
         if (cnt[id]!=2) {
            f=false;
            break;
         }
         id+=2;
         ans*=2;
         ans%=mod;
      }
   }
   else{
      for (int i =0;i < n/2;i++){
         int id=1;
         if (cnt[id]!=2) {
            f=false;
            break;
         }
         id+=2;
         ans*=2;
         ans%=mod;
      }
   }
   if (f) cout << ans << endl;
   else cout << 0 << endl;
   
   return 0;
}

