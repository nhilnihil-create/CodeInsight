#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int64_t ans=1;
  for (int i=1; i<N+1; i++) {
    ans=ans*i;
    ans=ans%1000000007;
  }
  cout << ans << endl;
}