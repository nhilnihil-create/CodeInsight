#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  cin >> N;
  vector<int> vec(N);
  rep(i, N) {
    cin >> vec.at(i);
  }
  ll co = 0;
  rep(i, N) {
    if(vec.at(vec.at(i) - 1) == i + 1) {
      co++;
    }
  }
  cout << co / 2 << endl;
}