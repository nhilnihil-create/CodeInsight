#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> a, b, c;
  set<int> s;
  int x;
  for(int i = 0; i < n; i++){
    cin >> x;
    c.push_back(x);
    if(i % 2 == 0){
      a.push_back(x);
      s.insert(x);
    }
    else{
      b.push_back(x);
    }
  }
  
  sort(c.begin(), c.end());
  
  for(int i = 0; i < n; i++){
    if(i % 2 == 0) s.insert(c.at(i));
  }
  
  cout << s.size() - a.size() << '\n';
}