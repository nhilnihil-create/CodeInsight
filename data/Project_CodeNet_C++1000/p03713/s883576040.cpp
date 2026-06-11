#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll h, w;
  cin >> h >> w;
  if(h%3==0 || w%3==0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = LLONG_MAX;
  ll a = w/3 -10;
  ll b = h/2 -10;
  rep(i,20)rep(j,20) {
    ll c = a+i;
    ll d = b+j;
    if(c<=0 || d<=0) continue;
    if(c>=w || d>=h) continue;
    ll s1 = c*h;
    ll s2 = (w-c)*d;
    ll s3 = h*w - s1 - s2;
    if(s1<=0 || s2<=0 || s3<=0) continue;
    ll smax = max(s1,max(s2,s3));
    ll smin = min(s1,min(s2,s3));
    ans = min(ans,smax-smin);
  }
  ll o = h/3 -10;
  ll p = w/2 -10;
  rep(i,20)rep(j,20) {
    ll q = o+i;
    ll r = p+j;
    if(q<=0 || r<=0) continue;
    if(q>=h || r>=w) continue;
    ll s1 = q*w;
    ll s2 = (h-q)*r;
    ll s3 = h*w - s1 - s2;
    if(s1<=0 || s2<=0 || s3<=0) continue;
    ll smax = max(s1,max(s2,s3));
    ll smin = min(s1,min(s2,s3));
    ans = min(ans,smax-smin);
  }
  ans = min(ans,h);
  ans = min(ans,w);
  cout << ans << endl;
  return 0;
}