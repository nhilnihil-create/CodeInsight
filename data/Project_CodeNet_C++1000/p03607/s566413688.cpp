#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> a;
  for(int i = 0; i < n; i++) {
    int ai;
    cin >> ai;
    if(a.count(ai)) a.erase(ai); 
    else a.insert(ai);
  }
  int ans = a.size();
  cout << ans;
}