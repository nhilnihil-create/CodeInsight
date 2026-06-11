#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  rep(i, M) cin >> a[i] >> b[i];
  
  int count;
  rep(i, N) {
    count=0;
  	rep(j,M) {
      if (a[j]==i+1) count++;
      if (b[j]==i+1) count++;
    }
    cout << count << endl;
  }
}
