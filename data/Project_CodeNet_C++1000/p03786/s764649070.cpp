#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

int main() {
  ll N;
  cin >> N;

  vector<ll> size(N);
  for (ll i = 0; i < N; i++) {
    cin >> size[i];
  }

  sort(size.begin(), size.end());

  ll sum = 0;
  ll t = 0;

  for (ll i = 0; i < N - 1; i++) {
    sum += size[i];
    if (sum * 2 < size[i + 1]) {
      t = i + 1;
    }
  }
  cout << (N - t) << endl;
}