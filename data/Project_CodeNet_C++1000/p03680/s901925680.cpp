#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  int count = 0, now = 1;
  // n回以内に見つからないならループしてるので不可能
  while (count < n && now != 2) {
    count++;
    now = a[now];
  }
  
  cout << (count == n ? -1 : count) << endl;
}