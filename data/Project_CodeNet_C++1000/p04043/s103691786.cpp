#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> l(11,0);
  int x;
  cin >> x;
  l[x]++;
  cin >> x;
  l[x]++;
  cin >> x;
  l[x]++;
  
  if (l[5] == 2 && l[7] == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
  
}