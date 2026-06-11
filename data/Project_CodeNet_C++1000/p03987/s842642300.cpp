#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int n; cin>>n; ll an=0;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  int b[n]; for(int i=0;i<n;i++) b[a[i]-1]=i;
  set<ll> s1; set<ll, greater<ll>> s2;
  for(int i=0,j=b[0];i<n;i++,j=b[i]) { // iがある場所がj
    auto it1=s1.lower_bound(j); // 右側
    auto it2=s2.lower_bound(j); // 左側
    ll x1, x2;
    if (it1 == s1.end()) x1=n-1-j+1;
    else {ll val=*it1; x1=val-j;}
    if (it2 == s2.end()) x2=j+1;
    else {ll val=*it2; x2=j-val;}
    //cout<<i<<" "<<j<<" "<<x1<<" "<<x2<<" "<<an<<endl;
    an+=x1*x2*(i+1);
    s1.insert(j); s2.insert(j);
  }
  cout<<an<<endl;
}