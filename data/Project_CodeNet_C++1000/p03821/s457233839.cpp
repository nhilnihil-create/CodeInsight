#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)

int main (){
 ll n; cin >> n;
 vector<ll> a(n),b(n);
 rep(i,n)cin >> a[i] >> b[i];

 ll cnt=0;
 for(ll i=n-1;i>=0;i--){
   a[i]+=cnt;
   if(a[i]%b[i]!=0){
   cnt+=(b[i]-a[i]%b[i]);
   }
 }
 cout << cnt << endl;

}
