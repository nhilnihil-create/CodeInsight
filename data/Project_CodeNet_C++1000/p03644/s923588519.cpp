#include<bits/stdc++.h>
using namespace std;
int main() {
  int two[7] = {1, 2, 4, 8, 16, 32, 64};
  int N, res;
  cin >> N;
  for(int i = 0; i < 7; i++) {
    if(two[i] <= N) res = two[i];
  }
  cout << res << endl;
}