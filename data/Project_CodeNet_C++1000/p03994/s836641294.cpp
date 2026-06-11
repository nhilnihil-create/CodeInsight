#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  
  int l = s.size();
  for(int i = 0; i < l; i++){
    char now = s.at(i);
    if(now == 'a' && i < l-1) continue;
    int dis = 'z' - now + 1;
    if(i == l-1) s.at(i) = 'a' + (s.at(i) + k - 'a') % 26;
    else if(k >= dis) s.at(i) = 'a', k -= dis;
  }
  
  cout << s << endl;
}