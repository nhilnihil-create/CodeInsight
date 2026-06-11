#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  vector<ll> X(N);
  for(int i = 0; i < N; i++){
    cin >> X[i];
  }
  ll ptr = X[0];
  ll res = 0;
  for(int i = 1; i < N; i++){
    res += min((X[i] - X[i-1]) * A, B);
  }
  cout << res << endl;
}
