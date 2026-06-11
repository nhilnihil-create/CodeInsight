#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n,0);
  for (int i = 0; i < n; i++) cin >> a[i];

  int now = 1;
  int count = 0;
  vector<int> arrived(n+1, 0);
  while(arrived[now] == 0){
    if (now == 2) {
      cout << count << endl;
      return 0;
    }
    arrived[now]++;
    now = a[now-1];
    count++;
  }
  cout << -1 << endl;
}
