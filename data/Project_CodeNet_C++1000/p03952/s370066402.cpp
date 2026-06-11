#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, x;
  cin >> n >> x;
  
  if(x == 1 || x == 2 * n - 1){
    cout << "No\n";
    return 0;
  }
  
  if(n == 2){
    cout << "Yes\n1\n2\n3\n";
    return 0;
  }
  
  vector<int> a(2 * n + 10, 0), ans(2 * n - 1, 0);
  if(x == 2){
    ans.at(n - 1) = 2;
    a.at(2)++;
    ans.at(n - 2) = 3;
    a.at(3)++;
    ans.at(n) = 1;
    a.at(1)++;
    ans.at(n + 1) = 4;
    a.at(4)++;
  }
  else{
    ans.at(n - 1) = x;
    a.at(x)++;
    ans.at(n - 2) = x - 1;
    a.at(x - 1)++;
    ans.at(n) = x + 1;
    a.at(x + 1)++;
    ans.at(n + 1) = x - 2;
    a.at(x - 2)++;
  }
  
  int now = 1;
  for(int i = 0; i < 2 * n - 1; i++){
    if(ans.at(i) == 0){
      if(a.at(now) == 0){
        ans.at(i) = now;
        a.at(now)++;
        now++;
      }
      else{
        now++;
        i--;
      }
    }
  }
  
  cout << "Yes\n";
  for(int i = 0; i < 2 * n - 1; i++){
    cout << ans.at(i) << '\n';
  }
}