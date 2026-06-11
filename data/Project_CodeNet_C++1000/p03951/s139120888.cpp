#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
  // input
    int n;cin >> n;
    string s,t; cin >> s >> t;
    string sn,tn;
    if(s == t){
      cout << n << endl;
      return 0;
    }

  // compute

  for(int i = 0; i < n ; i++) {
    sn = s.substr(i + 1);
    tn = t.erase(n - 1 - i);
      if(sn == tn ){
          cout << 2 * n - sn.size() << endl;
          return 0;
      }
  }

  // output  
    cout << 2 * n << endl;

}
