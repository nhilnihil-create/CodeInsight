#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  
  set<pair<int, int>> like;
  int ans = 0;
  for(int i = 0; i < n; i++){
    int x = i + 1, y = a.at(i);
    if(x > y) swap(x, y);
    pair<int, int> now = {x, y};
    if(like.count(now)) ans++;
    else like.insert(now);
  }
  
  cout << ans << endl;   
}