#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cassert>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int n,k; cin>>n>>k;
  ll a[n]; for(int i=0;i<n;i++) cin>>a[i];
  ll b1[n], b2[n]; b1[0]=max(0LL,a[0]); b2[n-1]=max(0LL,a[n-1]); 
  for(int i=1;i<n;i++) b1[i]=b1[i-1]+max(0LL,a[i]);
  for(int i=n-2;i>=0;i--) b2[i]=b2[i+1]+max(0LL,a[i]);
  ll nkb[n-k+1]; fill(nkb,nkb+n-k+1,0); // nkw[i]=0
  for(int i=0;i<k;i++) nkb[0]+=a[i];
  for(int i=k,j=0;i<n;i++,j++) nkb[j+1]=nkb[j]+a[i]-a[j];

  //for(int i=0;i<n;i++) cout<<b1[i]<<" "; cout<<endl;
  //for(int i=0;i<n;i++) cout<<b2[i]<<" "; cout<<endl;
  //for(int i=0;i<n-k+1;i++) cout<<nkb[i]<<" "; cout<<endl;

  ll an=-1e16;
  for(int i=0;i<n-k+1;i++) {
    ll sm=0;
    if (i-1 >= 0) sm+=b1[i-1];
    if (i+k < n) sm+=b2[i+k];
    sm += max(nkb[i], 0LL);
    an=max(an,sm);
  }
  cout<<an<<endl;
}