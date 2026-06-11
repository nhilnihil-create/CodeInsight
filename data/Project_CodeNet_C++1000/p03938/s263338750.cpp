#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p.at(i);
  
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++){
    a.at(i) = 20001 * (i + 1);
    b.at(i) = 20001 * (n - i);
  }
  
  for(int i = 0; i < n; i++){
    b.at(p.at(i) - 1) += i + 1;
  }
  
  // 出力
  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << a.at(i);
  }
  cout << '\n';
  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << b.at(i);
  }
  cout << '\n';
}