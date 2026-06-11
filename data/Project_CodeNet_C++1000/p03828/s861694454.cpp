#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  int N; cin >> N;
  map<int,int> map;
  for (int i =2; i<=N; i++) {
    int tmp =i;
    int j =2;
    while (tmp >1) {
      if (tmp % j ==0) {
        if (map[j] == 0) map[j] = 1;
        else map[j]++;
        tmp /= j;
        j =2;
      } else {
        j++;
      }
    }
  }
  long ans =1;
  for (auto x: map) {
    ans *= x.second +1;
    ans %= MOD;
  }
  cout << ans << endl;
}