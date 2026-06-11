#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N, K;
  cin >> N >> K;
  ll A, B;
  A = B = 0;
  ll X;
  rep(i, N) {
    cin >> X;
    if(X % 2 == 0) {
      A++;
    }
    else {
      B++;
    }
  }
  ll P = 1;
  rep(i, A) {
    P *= 2;
  }
  ll Q = 1;
  if(K == 0) {
    if(B == 0) {
      Q = 1;
    }
    else {
      rep(i, B - 1) {
        Q *= 2;
      }
    }
  }
  else {
    if(B == 0) {
      Q = 0;
    }
    else {
      rep(i, B - 1) {
        Q *= 2;
      }
    }
  }
  cout << P * Q << endl;
}