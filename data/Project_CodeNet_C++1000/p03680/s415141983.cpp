#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> buttens(n);	//ボタン一覧
  vector<bool> pushed(n);	//押されたボタン
  for (int i = 0; i < n; i++) {
    cin >> buttens.at(i);
  }
  
  int pushed_now = 0;
  int counter = 0;
  while(!pushed.at(pushed_now) && pushed_now != 1){
    pushed.at(pushed_now) = true;
    pushed_now = buttens.at(pushed_now) - 1;
    counter++;
  }
  
  if(pushed_now == 1) cout << counter << endl;
  else cout << -1 << endl;
}
