#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, L;
  cin >> N >> L;
  string C;
  vector<string> vec(N);
  rep(i, N) {
    cin >> C;
    vec.at(i) = C; 
  }
  sort(vec.begin(), vec.end());
  rep(i, N) {
    cout << vec.at(i);
  }
}
