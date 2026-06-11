#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll n; cin>>n;
  vector<ll> A(n);
  rep(i,n)
  {
    cin>>A.at(i);
  }
  vector<ll> b(0);
  if(n%2==0)
  {
    rep(i,n/2)
    {
      b.push_back(A.at(n-2*i-1));
    }
    rep(i,n/2)
    {
      b.push_back(A.at(2*i));
    }
    rep(i,n) {cout<<b.at(i)<<" ";} 
    cout<<endl;
    return 0;
  }
  rep(i,(n+1)/2)
  {
    b.push_back(A.at(n-2*i-1));
  }
  rep(i,(n-1)/2) {b.push_back(A.at(2*i+1));}
  rep(i,n) {cout<<b.at(i)<<" ";}
  cout<<endl;
  return 0;
}