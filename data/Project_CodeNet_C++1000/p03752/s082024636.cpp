#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int K, N;
long long a[15];

int main() {
  cin >> N >> K;
  rep(i, N) {
    cin >> a[i];
  }

  long long b[15];
  long long cost;
  long long ans = 100000000000;

  for(int bit = 0; bit < (1<<N); bit++) {
    int count = 1;
    cost = 0;
    for(int i = 0; i < N; i++) {
      b[i] = a[i];
    }
    long long compare = a[0];

    for(int i = 1; i < N; i++) {
      if(bit & (1<<i)) {
        count++;
        if(a[i] <= compare) {
          b[i] = compare + 1;
          cost += compare + 1 - a[i];
        }
        compare = b[i];
      } else {
        if(a[i] > compare) {
          count++;
          compare = a[i];
        }

      }
    }
    if(count >= K) ans = min(cost, ans);
  }

  cout << ans << endl;
  return 0;
}