#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,b,c,d;cin >> n >> a >> b >> c >> d;
  vector<ll> l(n+1),r(n+1);
  l[0]=-(n-1)*d;
  r[0]=-(n-1)*c;
  for(int i=1;i<=n-1;i++){
    l[i]=l[i-1]+c+d;
    r[i]=r[i-1]+c+d;
  }
  ll t=abs(a-b);
  for(int i=0;i<=n-1;i++){
    if(l[i]<=t&&t<=r[i]){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}