#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;
const int mod=1000000007;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  ll ans=1;
  int before=0;
  rep(i,n) {
    if (i==n-1||s[i]!=s[i+1]) {
      if (before==0) {
	ans*=3;
      }
      else if (before==1) {
	ans*=2;
      }
      before=1;
      ans%=mod;
    }
    else {
      if (before==0) {
	ans*=6;
      }
      else if (before==1) {
	ans*=2;
      }
      else {
	ans*=3;
      }
      before=2;
      ans%=mod;
      i++;
    }
  }
  cout<<ans<<endl;
  return 0;
}

