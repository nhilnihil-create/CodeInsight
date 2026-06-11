#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> p, q;
  rep(i,n) {
    if (s[i] == 'A') p.push_back(i);
    if (s[i] == 'Z') q.push_back(i);
  }
  
  cout << max(0, q[q.size()-1]-p[0]+1) << endl;
}