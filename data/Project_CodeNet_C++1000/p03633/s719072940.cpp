#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
  ll N;
  cin>>N;
  vector<ll>T(N);
  ll  ans;
  rep(i,N){
      cin>>T[i];
    if(i==0){
        ans=T[0];
    }
    else{
        ans=T[i]/__gcd(T[i],ans)*ans;
    }
  }
  cout<<ans<<endl;
}
