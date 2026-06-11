#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> done(n, 0);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }
  int acount = 0;
  int now = 1;
  while(true) {
    if (done[now-1] == 1) {
      cout << -1 << endl;
      return 0;
    }
    done[now-1] = 1;
    now = a[now-1];
    acount++;
    if (now == 2) {
      cout << acount << endl;
      return 0;
    }
  }
}
  
