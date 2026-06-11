#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  ll ans[2]={0,0};

  for(ll i=0;100*a*i<=f;i++){
    for(ll j=0;100*a*i+100*b*j<=f;j++){
      ll res=f-(100*(a*i+b*j));
      for(ll k=0;k*c<=res;k++){
        for(ll l=0;k*c+l*d<=res;l++){
          ll sug=k*c+l*d;
          ll wat=100*(a*i+b*j);
          if(k*c+l*d>e*(a*i+b*j))continue;

          //cout << (wat+sug) << " " << sug << endl;
          if(ans[1]*(wat+sug)<=ans[0]*sug){
            ans[0]=(wat+sug);
            ans[1]=sug;
          }
        }
      }
    }
  }
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}