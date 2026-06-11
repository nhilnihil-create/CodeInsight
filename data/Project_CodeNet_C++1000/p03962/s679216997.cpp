#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b, c;
  cin >> a >> b >> c;
  
  set<int> S;
  
  S.insert(a);
  S.insert(b);
  S.insert(c);
  
  cout << S.size() << endl;  
  
return 0;
}