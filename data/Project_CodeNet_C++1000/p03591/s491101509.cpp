#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  string S;
  cin >> S;
  
  if(S.size() < 4 ){
    cout << "No" << endl;
    return 0;
  }
  if( S.compare(0, 4, "YAKI") == 0 ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
