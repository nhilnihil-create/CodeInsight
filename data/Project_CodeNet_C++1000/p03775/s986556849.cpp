#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
  ll n;
  cin >> n;
  ll ans=1000000000000;
  for(int i=1;i<=sqrt(n);i++){
     if(n%i==0){
        ll mx=0;
        ll a=i;
        ll b=n/a;
        int aa=1;
        while(a>=10){
           a/=10;
           aa++;
        }
        int bb=1;
        while(b>=10){
           b/=10;
           bb++;
        }
      mx=max(aa,bb);
      ans=min(ans,mx);
     }
  }
  cout << ans << endl;
}