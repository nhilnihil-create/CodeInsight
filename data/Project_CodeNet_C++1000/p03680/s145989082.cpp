#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  int count=0;
  int curr=1;
  
  rep(i, N) {
    count++;
    curr=a[curr-1];
    if (curr==2) {
      cout << count << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
