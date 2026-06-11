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
  
  ll A[3*n];
  rep(i,3*n) cin>>A[i];

  sort(A,A+3*n);
  
  ll sum=0;
  for(int i=3*n-2;i>n-1;i-=2){
    sum+=A[i];
  }
  
  cout<< sum <<endl;
  
  return 0;
}