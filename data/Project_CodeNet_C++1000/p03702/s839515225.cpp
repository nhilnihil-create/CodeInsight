#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)
ll n,a,b,h[100010];
bool f(ll m){
  ll q=0;
  fr(i,n){
    if(h[i]<=b*m) continue;
    q+=(h[i]-b*m-1)/(a-b)+1;
  }
  return q<=m;
}

int main(){
  cin>>n>>a>>b;
  fr(i,n) cin>>h[i];
  sort(h,h+n);
  ll l=0,r=1e9,m;
  while(r-l>1){
    m=(l+r)/2;
    if(f(m)) r=m;
    else l=m;
  }
  cout<<r<<endl;
}