#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

int main() {
  ll n;
  cin>>n;
  
  vector<ll> A(3*n);
  rep(i,3*n) cin>>A[i];

  sort(ALL(A),greater<int>());
  
  ll sum=0;
  for(int i=1;i<=n;i++){
    sum+=A[2*i-1];
  }
  
  cout<< sum <<endl;
  
  return 0;
}