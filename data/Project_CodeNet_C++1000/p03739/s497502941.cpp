#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++)
#define ll long long
using namespace std;

int main() {
  int n; cin >> n;
  ll a[n],b[n],s[n],t[n]; bool check = true; 
  
  rep(i,0,n) {
    cin >> a[i]; b[i] = a[i];
  }
  s[0] = a[0]; t[0] = s[0];
  
  ll ans1 =0;
  rep(i,0,n) {
    if (i >=1) t[i] = t[i-1] + b[i];
    if (i % 2 ==0) {
      if (t[i] <=0) {
        ans1 += 1 - t[i]; b[i] += 1 - t[i]; t[i] = 1;
      } 
      if (b[i] <=0) {
        ans1 += 1 - b[i]; b[i] = 1;
      }
    }
    if (i % 2 ==1) {
      if (t[i] >=0) {
        ans1 += t[i] + 1; b[i] -= t[i] + 1; t[i] = -1;
      }
      if (b[i] >=0) {
        ans1 += b[i] + 1; b[i] = -1;
      }
    } 
  }

  ll ans2 =0;
  rep(i,0,n) {    
    if (i >=1) s[i] = s[i-1] + a[i];
    if (i % 2 ==1) {
      if (s[i] <=0) {
        ans2 += 1 - s[i]; a[i] += 1 - s[i]; s[i] = 1;}
      if (a[i] <=0) {
        ans2 += 1 - a[i]; a[i] = 1;}  
    }
    if (i % 2 ==0) {
      if (s[i] >=0) {
        ans2 += s[i] + 1; a[i] -= s[i] + 1; s[i] = -1; }
      if (a[i] >=0) {
        ans2 += a[i] + 1; a[i] = -1;}  
    } 
  }
  ll ans = min(ans1,ans2);
  cout << ans << endl;
}