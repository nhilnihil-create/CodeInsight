#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int N = 0,M = 0;
  cin >> N >> M;
  if(abs(N - M) > 1){
    cout << 0;
    return 0;
  }
  ll x = 1,y = 1;
  for(ll a = 1; a <= N; a++){
    x = (x * a) % 1000000007;
  }
  for(ll b = 1; b <= M; b++){
    y = (y * b) % 1000000007;
  }
  
  if(abs(N - M) == 1){
    cout << (x * y) % 1000000007;
  }
  if(abs(N - M) == 0){
    cout << (x * y * 2) % 1000000007;
  }
}