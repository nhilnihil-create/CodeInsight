#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n,a,b;cin>>n>>a>>b;
  ll score=0;
  ll an[n];rep(i,n)cin>>an[i];
  rep(i,n-1) {
    score += min( (an[i+1]-an[i])*a, b );
  }
  cout << score;
}
