#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  string S;
  cin >> S;
  int firstA=-1, lastZ=-1;
  int n = S.size();

  for (int i=0; i < n; ++i) {
    if (S[i] == 'A') {
      firstA = i;
      break;
    }
  }
  for (int i=n-1; i >= 0; --i) {
    if (S[i] == 'Z') {
      lastZ = i;
      break;
    }
  }
  cout << lastZ - firstA + 1 << endl;

  return 0;
}