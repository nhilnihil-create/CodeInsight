#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  string S;
  cin >> S;


  for (int i = 0, s_len = S.size(); i < s_len; i += 2) {
    cout << S[i];
  }

  return 0;
}