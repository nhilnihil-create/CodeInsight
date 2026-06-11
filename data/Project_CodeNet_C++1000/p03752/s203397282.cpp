#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i=0; i<n; i++)



int main() {
  ll n,k;
  cin>>n>>k;
  ll a[n];
  ll ok=0,temp1=0;
  rep(i,n) cin>>a[i];
  rep(i,n){
      if(temp1<a[i]) ok++,temp1=a[i];
      else break;
  }
  if(k<=ok){
      cout<<0<<endl;
      return 0;
  } 
  ll ans=100000000000000000;
  for(ll bit=0;bit<(1LL<<(n-ok));bit++){

      ll cansee=0;
      for(ll i=0;i<n-ok;i++){
          if(bit&(1LL<<i)) cansee++;
      }
      if(cansee>=k-ok){
          ll temp2=temp1;
          ll yen=0;

          for(ll i=0;i<n-ok;i++){

            if(bit&(1LL<<i)){
                if(temp2==a[i+ok]){
                     yen++;
                    temp2++;
                }
                else if(temp2>a[i+ok]){
                     yen+=(temp2-a[i+ok]+1);
                    temp2++;
                }
                else{
                    temp2=a[i+ok];
                } 
            }
            else{
                if(temp2<a[i+ok]) temp2=a[i+ok];
            }

          }
          ans=min(ans,yen);

      }
      
  }

  cout<<ans<<endl;

}