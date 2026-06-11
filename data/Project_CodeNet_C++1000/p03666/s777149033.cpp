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
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  ll k=b-a;
  bool ok=false;
  for(int i=-n+1;i<=n-1;i++){    
    ll j=n-1-abs(i);
    rep(l,2){
      j=j*pow(-1,l);
      ll low=i*d+j*c;
      ll high=(i+j)*d;
      if(low>high) swap(low,high);
      if(low<=k && k<=high) ok=true;     
    }
  }
  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;

  
  return 0;
    

}
