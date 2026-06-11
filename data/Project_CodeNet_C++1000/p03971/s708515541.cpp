#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  ll X = 1;
  ll Y = 1;
  rep(i, N) {
    if(S.at(i) == 'a' && X <= A + B) {
      X++;
      cout << "Yes" << endl;
    }
    else if(S.at(i) == 'b' && (X <= A + B && Y <= B)) {
      X++;
      Y++;
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}