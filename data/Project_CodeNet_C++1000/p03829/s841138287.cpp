#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N;
  ll A,B,cost = 0;
  cin >> N >> A >> B;
  vector<ll> X(N);
  rep(i,N) cin >> X[i];
  rep(i,N-1) {
    if ((X[i+1]-X[i])*A>B) cost+=B;
    else cost += (X[i+1]-X[i])*A;
  }
  cout << cost << endl;
} 