#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n;cin >> n;
  vector<ll> a(3*n),c(3*n),d(3*n);
  priority_queue<ll> pqr;
  priority_queue<ll,vector<ll>,greater<ll>> pql;
  ll suml=0,sumr=0;
  for(int i=0;i<3*n;i++){
    cin >> a[i];
    if(i<n){
      pql.push(a[i]);
      suml+=a[i];
    }
    if(i>=2*n){
      pqr.push(a[i]);
      sumr+=a[i];
    }
  }
  c[n-1]=suml;
  d[2*n]=sumr;
  for(int i=n;i<2*n;i++){
    if(pql.top()<a[i]){
      c[i]=c[i-1]+a[i]-pql.top();
      pql.pop();
      pql.push(a[i]);
    }
    else{
      c[i]=c[i-1];
    }
  }
  for(int i=2*n-1;i>=n;i--){
    if(pqr.top()>a[i]){
      d[i]=d[i+1]+a[i]-pqr.top();
      pqr.pop();
      pqr.push(a[i]);
    }
    else{
      d[i]=d[i+1];
    }
  }
  ll ans=-1e18;
  for(int i=n-1;i<2*n;i++){
    ans=max(ans,c[i]-d[i+1]);
  }
  cout << ans << endl;
}