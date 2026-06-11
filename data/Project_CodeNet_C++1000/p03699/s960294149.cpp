#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> s(n);
  int score = 0, mi = 100000;
  for(int i = 0; i < n; i++){
    int now;
    cin >> now;
    score += now;
    if(now % 10) mi = min(mi, now);
  }
  
  if(score % 10) cout << score << endl;
  else if(mi % 10) cout << score - mi << endl;
  else cout << 0 << endl;
}