#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  ll a[n];
  
  rep(i,n) cin >> a[i];
  ll ans=(a[0]-1LL);
  ll k=1LL;
  rep1(i,n-1){
    //    cout << ans << endl;
    if(a[i]<=k+1) k= max(a[i],k);
    else{
      ans+=(a[i]-1)/(k+1);
    }
    //    cout << ans << endl;
  }
  cout << ans << endl;

  
  return 0;
    

}
