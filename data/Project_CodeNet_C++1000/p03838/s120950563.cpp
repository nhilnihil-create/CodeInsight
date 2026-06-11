#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll x,y;
  cin >> x >> y;
  ll ans=0;
  if(x<0&&y<0) {
    if(x>y) {
      ans=2+abs(y)-abs(x);
    }
    else if(x<y) {
      ans=abs(abs(y)-abs(x));
    }
  }
  else if(x<0) {
    if(y!=0) {
      ans=1+abs(abs(x)-abs(y));
    }
    else {
      ans=abs(x);
    }
  }
  else if(y<0) {
    ans=1+abs(abs(x)-abs(y));
  }
  else if(x==0) {
    ans=abs(y);
  }
  else if(y==0) {
    ans=abs(x)+1;
  }
  else {
    ans=abs(x-y);
    if(x>y) {
      ans+=2;
    }
  }
  cout << ans << endl;
}