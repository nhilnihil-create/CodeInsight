#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;

int main()
{
	ll a,b,c;
  cin >> a>>b>>c;
  ll ans=0;
  if(a%2==1||b%2==1||c%2==1){
    cout << ans << endl;
    return 0;
  }
  if(a==b&&b==c) {
    cout << -1 << endl;
    return 0;
  }
  while(true){
    if(a%2==1||b%2==1||c%2==1){
      break;
    }
    ll tmpA,tmpB,tmpC;
    tmpA=b/2+c/2;
    tmpB=a/2+c/2;
    tmpC=a/2+b/2;
    a=tmpA;
    b=tmpB;
    c=tmpC;
    ans++;
  }
  cout <<ans<<endl;
}