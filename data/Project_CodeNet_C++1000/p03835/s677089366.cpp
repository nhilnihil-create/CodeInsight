#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int64_t K, S, ans;
  cin >> K >> S;
  ans=0;
  for (int X=0; X<=K; X++) {
    for (int Y=0; Y<=K; Y++) {
      if (0<=S-X-Y && S-X-Y<=K) {
        ans=ans+1;
      }
    }
  }
  cout << ans << endl;
}
