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
  bool ok=true;
  
  ll sum=0;
  ll d[n];
  d[0]=a[0]-a[n-1];
  ll k;
  rep(i,n) sum+=a[i];
  k=sum*2LL/n/(n+1);
  //  cout << sum << endl;
  if(k*n*(n+1)/2LL!=sum){
    ok=false;
  }
  rep1(i,n-1) d[i]= a[i]-a[i-1];

  ll ans_s=0;
  rep(i,n){
    if((k-d[i])%n!=0) ok=false;
    if(k<d[i]) ok=false;
    ans_s += k-d[i];
  }
  //  cout << "k " << k << " ans_s " << ans_s << " " << ok <<endl;
  if(ans_s!=n*k) ok = false;
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  
  return 0;
    

}
