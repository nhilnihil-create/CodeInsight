#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  ll N,C,K;
  cin >> N >> C >> K;
  vector<ll> T(N);
  rep(i,N){
    cin >> T.at(i);
  }
  ll bus = 0;
  sort(T.begin(),T.end());
  for( ll p = 0;p<N;p++){
    ll q = p;
    while(T.at(q) <= T.at(p) + K){
      q++;
      if(q - p == C){
        break;
      }
      if(q == N ){
        break;
      }
    }
    bus++;
    p = q - 1;
  }
  cout << bus << endl;
}
      