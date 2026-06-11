#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
  int n; cin >> n;
  vector<ll> a(n); rep(i,n) cin >> a[i];
  bool flg = true;
  //e+e=e o+o=e
  rep(i,n){
    if(a[i]%2==1) flg = !flg;
  }
  if(flg) cout << "YES" << endl;
  else cout << "NO" << endl;  
  return 0;
}

