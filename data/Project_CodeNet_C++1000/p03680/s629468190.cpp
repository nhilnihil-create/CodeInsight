#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(n), b(n, 0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mem = 0;
  
  while (true){
    if (b[mem] == 1){
      ans = -1;
      break;
    }
    ans++;
    if (a[mem] == 2) break;
    b[mem] = 1;
    mem = a[mem];
    mem--;
  }
  cout << ans << endl;
}
    