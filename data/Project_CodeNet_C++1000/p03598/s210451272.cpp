#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, K;
  int sum=0;
  cin >> N >> K;
  
  rep(i, N) {
    int x;
    cin >> x;
    if (x < K-x) sum += x;
    else sum += K-x;
  }
  
  cout << 2*sum << endl;
}
