#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N;
  cin >> N;
  vector<ll> vec(2 * N);
  rep(i, N * 2) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  ll sum = 0;
  rep(i, N * 2) {
    sum += vec.at(i);
    i++;
  }
  cout << sum;
}
