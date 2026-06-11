#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> l(N);
  rep(i, 0, N) {
    cin >> l.at(i);
  }

  sort(l.begin(), l.end());

  int Ans = 0;
  rep(i, 0, K) {
    Ans += l.back();
    l.pop_back();
  }

  cout << Ans << endl;
}
