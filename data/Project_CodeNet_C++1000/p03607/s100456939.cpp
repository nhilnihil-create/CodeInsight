#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
  int n; cin >> n;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  sort(a,a+n);
  int b,ans=0;
  bool p = false;
  rep(i,n){
    if(i==0){
      b = a[i];
      p = !p;
      continue;
    }
    if(a[i] == b) p = !p;
    else {
      if(p) ans++;
      p = true;
    }
    b = a[i];
  }
  if(p) ans++;
  cout << ans << endl;
  return 0;
}