#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;
  
  vector<int> x(n);
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    x.at(a - 1)++;
    x.at(b - 1)++;
  }
  
  bool judge = true;
  for(int i = 0; i < n; i++){
    if(x.at(i) % 2 == 1) judge = false;
  }
  
  if(judge) cout << "YES\n";
  else cout << "NO\n";
}