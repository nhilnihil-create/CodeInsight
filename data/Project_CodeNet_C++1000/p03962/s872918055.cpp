#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  
  set<int> S;
  S.insert(a);
  S.insert(b);
  S.insert(c);
  
  if(S.size() == 3){
    cout << 3 << endl;
  }
  if(S.size() == 2){
    cout << 2 << endl;
  }
  if(S.size() == 1){
    cout << 1 << endl;
  }


}
 