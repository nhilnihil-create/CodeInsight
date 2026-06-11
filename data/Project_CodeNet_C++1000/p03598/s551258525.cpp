#include <array>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K, x;
  cin >> N >> K;
  int dist = 0;
  for (size_t i = 0; i < N; i++) {
      cin >> x; 
      if (K < x) {
          dist += (x - K); 
      } else {
        dist += (x > (K - x)) ? (K - x) :  x;
      }
  }

  cout << dist * 2;
}
