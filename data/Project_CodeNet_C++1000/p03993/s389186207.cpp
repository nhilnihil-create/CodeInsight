#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans = 0;
  cin >> n;
  vector<int>data(n);
  for(int i = 0;i < n;i++){
    cin >> data[i];
    data[i]--;
  }
  for(int i = 0;i < n;i++){
    if(data[data[i]] == i) ans++;
  }
  cout << ans/2 << endl;
}
