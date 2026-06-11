#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string X;
  cin >> X;
  ll N, S, W, E;
  N = S = W = E = 0;
  rep(i, X.size()) {
    if(X.at(i) == 'W') {
      W++;
    }
    if(X.at(i) == 'E') {
      E++;
    }
    if(X.at(i) == 'S') {
      S++;
    }
    if(X.at(i) == 'N') {
      N++;
    }
  }
  if((N > 0 && S > 0) && (W == 0 && E == 0)) {
    cout << "Yes" << endl;
  }
  else if((N == 0 && S == 0) && (W > 0 && E > 0)) {
    cout << "Yes" << endl;
  }
  else if((N > 0 && S > 0) && (W > 0 && E > 0)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}