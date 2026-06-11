#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin>>N;
  vector<ll> S(N);
  for(int i = 0; i < N; i++){
    ll x;
    cin>>x;
    if(i==0)S[i]=x;
    else S[i]=S[i-1]+x;
  }
  ll m=0LL,n=0LL;
  ll d=0LL,e=0LL;
  for(int i = 0; i < N; i++){
    if(i%2==0){
      if(S[i]+m>=0LL) {
        d+=abs(S[i]+1LL+m);
        m-=S[i]+1LL+m;
      }
      if(S[i]+n<=0LL) {
        e+=abs(S[i]+n)+1LL;
        n+=abs(S[i]+n)+1LL;
      }
    }
    if(i%2==1){
      if(S[i]+m<=0LL){
        d+=abs(S[i]+m)+1LL;
        m+=abs(S[i]+m)+1LL;
      }
      if(S[i]+n>=0LL){
        e+=abs(S[i]+1LL+n);
        n-=S[i]+1LL+n;
      }
    }
    
  }
  cout<<min(d,e)<<endl;
}
      