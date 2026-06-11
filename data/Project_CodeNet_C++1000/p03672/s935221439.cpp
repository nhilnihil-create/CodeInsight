#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
#define all(a) a.begin(), a.end() 
using namespace std;

bool check(string s) {
  int n = s.size() / 2;
  rep(i, n) {
    if(s[i] != s[n+i]) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  if(s.size()%2==0) s.erase(s.size()-2, 2);
  else s.erase(s.size()-1, 1);
  
  while(!check(s)) {
    s.erase(s.size()-2, 2);
  }
  
  cout << s.size() << endl;
  
  return 0;
}
