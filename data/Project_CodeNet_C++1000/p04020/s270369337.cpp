#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

ll const mod = 1e9+7;


int main() {
  int N;
  ll cnt = 0;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  rep(i,N) {
    if (A[i]%2==1 && A[i+1]>0 && i<N-1) {
      A[i+1]--;A[i]++;
    }
    cnt += A[i]/2;
  }
  cout << cnt <<  endl;
}