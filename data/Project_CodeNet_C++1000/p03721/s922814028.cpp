#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N, K;
  cin >> N >> K;
  vector<long long> cnt(1e5 + 1, 0);
  for(int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    cnt[a] += b;
  }

  for(int i = 1; i <= 1e5; i++) {
    if(K <= cnt[i]) {
      cout << i << endl;
      break;
    }
    K -= cnt[i];
  }

  return 0;
}
