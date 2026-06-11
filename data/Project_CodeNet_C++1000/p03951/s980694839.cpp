#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s,t;
  cin >> s;
  cin >> t;
  for(int i=0;i<n;i++){
    if(s.substr(i)==t.erase(n-i)){
      cout << n+i << endl;
      return 0;
    }
  }
  cout << 2*n << endl;
}
