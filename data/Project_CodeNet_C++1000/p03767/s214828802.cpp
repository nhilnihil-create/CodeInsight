#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  long long Sum=0;
  cin >> N;
  vector<int> A(N*3);
  rep(i, N*3) cin >> A.at(i);
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  for(int i=1; i<N*2; i=i+2) Sum+=A.at(i);
  cout << Sum << endl;
}