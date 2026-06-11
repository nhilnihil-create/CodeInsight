#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  int n;
  const ll mod = 1e9+7;
  cin>>n;
  vector<ll> t(n);
  vector<ll> a(n);
  rep(i,n)cin>>t[i];
  rep(i,n)cin>>a[i];
  if(n==1) {
    if(t[0]==a[0]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  vector<ll> h(n);
  ll ans=1;
  ll h0=t[0];
  if(a[0]>a[1]) {
    if(a[0]==h0) {
      ans*=1;
    } else {
      ans*=0;
    }
  } else {
    if(h0<=a[0]) {
      ans*=1;
    } else {
      ans*=0;
    }
  }
  repeat(i,1,n-1) {
    if(t[i-1]<t[i]) {
      ll h = t[i];
      if(a[i]>a[i+1]) {
        if(a[i]==h) {
          ans*=1;
        } else {
          ans*=0;
        }
      } else {
        if(h<=a[i]) {
          ans*=1;
        } else {
          ans*=0;
        }
      }
    } else {
      // h<=t[i]
      if(a[i]>a[i+1]) {
        ll h = a[i];
        if(h<=t[i]) {
          ans*=1;
        } else {
          ans*=0;
        }
      } else {
        ans*=min(a[i],t[i]);
      }
    }
    ans%=mod;
  }
  ll hn1=a[n-1];
  if(t[n-1]>t[n-2]) {
    if(t[n-1]==hn1) {
      ans*=1;
    } else {
      ans*=0;
    }
  } else {
    if(hn1<=t[n-1]) {
      ans*=1;
    } else {
      ans*=0;
    }
  }
  cout << ans << endl;
  return 0;
}
