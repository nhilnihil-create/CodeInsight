#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;

int Buildings[15];

int main(void) {
  int N, K;
  cin >> N >> K;
  rep(i, N) cin >> Buildings[i];

  ll min_fee = -1;
  for (int bit = 0; bit < (1 << N); ++bit) {
    vector<int> sel(N, 0);
    for (int i = 0; i < N; ++i) {
      if (((1 << i) & bit) != 0) {
        sel[i] = 1;
      }
    }

    ll tallest = Buildings[0];
    ll can_see = 1;
    ll fee = 0;
    for (int i = 1; i < N; ++i) {
      if (sel[i] && Buildings[i] <= tallest) {
        tallest++;
        fee += tallest - Buildings[i];
        can_see++;
      } 

      if (Buildings[i] > tallest) {
        tallest = Buildings[i];
        can_see++;
      }
    }
    if (can_see >= K) {
      if (min_fee == -1 || min_fee > fee) min_fee = fee;
    }
  }
  if(min_fee == -1)
    min_fee = 0;
  cout <<  min_fee << endl;

  return 0;
}
