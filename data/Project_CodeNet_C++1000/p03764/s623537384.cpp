#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main(){
  int N,M;
  cin >> N >> M;
  vector<i64> x(N),y(M);
  i64 MOD = 1e9 + 7;
  i64 X = 0;
  rep(i,0,N - 1){
    cin >> x[i];
    if(i > 0){
      i64 d = x[i] - x[i - 1];
      X += d * (i) % MOD * (N - i);
      X %= MOD;
    }
  }
  i64 Y = 0;
  rep(i,0,M - 1){
    cin >> y[i];
    if(i > 0){
      i64 d = y[i] - y[i - 1];
      Y += d * (i) % MOD * (M - i);
      Y %= MOD;
    }
  }
  cout << X * Y % MOD << endl;
}
