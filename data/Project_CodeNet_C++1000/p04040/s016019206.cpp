#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

ll modpow(ll b, ll e, ll p) {
  if(e==0) return 1;
  if(e%2==0) {
    ll t = modpow(b,e/2,p);
    return (t*t)%p;
  }
  return (b*modpow(b,e-1,p))%p;
}

ll modinv(ll n, ll p) {
  return modpow(n,p-2,p);
}

ll modcomb(ll n, ll k, ll p) { // O(k)
  ll ans=1;
  for(ll i=n; i>=n-k+1; i--) {
    ans*=i;
    ans%=p;
  }
  for(ll i=1; i<=k; i++) {
    ans*=modinv(i,p);
    ans%=p;
  }
  return ans;
}

const ll p = 1e9+7;
const int MX = 1000000;
ll modFact[MX+1];
ll modFactInv[MX+1];
void precalc() {
  modFact[0]=1;
  modFactInv[0]=1;
  repeat(i,1,MX+1) {
    modFact[i]=(modFact[i-1]*i)%p;
    modFactInv[i]=modinv(modFact[i],p);
  }
}

ll fastModComb(ll n, ll k, ll p) {
  // call precalc() first.
  ll ret=modFact[n];
  ret=ret*modFactInv[n-k];
  ret%=p;
  ret=ret*modFactInv[k];
  ret%=p;
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  ll h,w,a,b;
  cin>>h>>w>>a>>b;
  ll ans=0;
  precalc();
  // rep(i,10) {
  //   cout << "modFact["<<i<<"]="<<modFact[i]<<endl;
  //   cout << "modFactInv["<<i<<"]="<<modFactInv[i]<<endl;
  // }
  for(ll i=b+1; i<w+1; i++) {
    ans+=(fastModComb(h-a-1+i-1,i-1,p)*fastModComb(a-1+w-i,w-i,p))%p;
    ans%=p;
  }
  cout << ans << endl;
  return 0;
}
