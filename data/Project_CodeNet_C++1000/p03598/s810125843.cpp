#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, K;
  cin >> N >> K;
  int x[N];
  rep(i,N) cin >> x[i];

  int sum = 0;
  rep(i,N){
    sum += min( 2 * x[i], abs(2 * (K - x[i])));
  }

  cout << sum << endl;
}
