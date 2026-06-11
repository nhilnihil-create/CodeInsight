#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;

ll combination(int n,int r) {
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  for (int i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    divisor  *= i;
  }
  return dividend / divisor;
}

int main() {
 int n,p; cin >> n >> p;
 vector<int> a(n);
 int cnt0=0,cnt1=0;
 rep(i,n){
   int ai;cin >> ai;
   int ad=ai%2;
   a[i]=ad;
   if(ad==1)cnt1++;
   else cnt0++;
 }

 ll power=pow(2,cnt0);
 ll sum=0;

 rep(i,cnt1+1){
   if(i%2==p){
     ll res=combination(cnt1,i)*power;
     sum+=res;
   }
 }
 cout << sum << endl;

}