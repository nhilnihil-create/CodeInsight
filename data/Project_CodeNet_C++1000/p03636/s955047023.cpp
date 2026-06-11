#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S;
  cin >> S;
  
  int cnt=0;
  cnt = S.size();
  
  cout << S.at(0) << cnt-2 << S.at(cnt-1) << endl;  
    
}
