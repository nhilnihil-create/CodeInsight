//In The Name Of GOD
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
const ll inf = 200000000000000;
const ll maxn = 5000;
#define pb push_back
#define mp make_pair
#define IO ios_base::sync_with_stdio(false);
int main(){
  IO;
  ll n,x,mini=inf;
  cin>>n>>x;
  ll A[n], B[n], C[n];
  for(ll i=0;i<n;i++){
    cin>>A[i];
    B[i]=C[i]=A[i];
  }
  for(ll i=0;i<n;i++){
    ll sum=0;
    for(ll j=0;j<n;j++){
      B[j]=min(B[j],A[(i+j)%n]);
      sum+=B[j];
    }
    mini=min(sum+x*i,mini);
  }
  for(ll i=0;i<n;i++){
    ll sum=0;
    for(ll j=0;j<n;j++){
      C[j]=min(C[j],A[(j-i+n)%n]);
      sum+=C[j];
    }
    mini=min(sum+x*i,mini);
  }
  cout<<mini;
}
