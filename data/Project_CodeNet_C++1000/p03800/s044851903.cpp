#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> check0={0,0,1,1};
  vector<ll> check1={0,1,0,1};
  for(ll k=0;k<4;k++) {
    bool flag=true;
    vector<ll> ans(n,-1);
    ans[0]=check0[k];
    ans[1]=check1[k];
    for(ll i=1;i<=n;i++) {
      if(i==n-1) {
        if(s[i]=='o') {
          if(ans[i]) {
            if(ans[0]!=1-ans[i-1]) {
              flag=false;
            }
          }
          else {
            if(ans[0]!=ans[i-1]) {
              flag=false;
            }
          }
        }
        else {
          if(ans[i]) {
            if(ans[0]!=ans[i-1]) {
              flag=false;
            }
          }
          else {
            if(ans[0]!=1-ans[i-1]) {
              flag=false;
            }
          }
        }
      }
      else if(i==n) {
        if(s[0]=='o') {
          if(ans[0]) {
            if(ans[n-1]!=1-ans[1]) {
              flag=false;
            }
          }
          else {
            if(ans[n-1]!=ans[1]) {
              flag=false;
            }
          }
        }
        else {
          if(ans[0]) {
            if(ans[n-1]!=ans[1]) {
              flag=false;
            }
          }
          else {
            if(ans[n-1]!=1-ans[1]) {
              flag=false;
            }
          }
        }
      }
      else if(s[i]=='o') {
        if(ans[i]) {
          ans[i+1]=1-ans[i-1];
        }
        else {
          ans[i+1]=ans[i-1];
        }
      }
      else {
        if(ans[i]) {
          ans[i+1]=ans[i-1];
        }
        else {
          ans[i+1]=1-ans[i-1];
        }
      }
    }
    if(flag) {
      for(ll j=0;j<n;j++) {
        if(ans[j]) {
          cout << "W";
        }
        else {
          cout << "S";
        }
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}