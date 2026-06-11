#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  int count = 0;
  bool flag = false;
  for (int i = 0; i < n; ++i) {
        if (s.substr(i) == t.substr(0, n-i)) {count = i + n;flag = true; break;}
    }
  cout << (flag ? count : 2 * n) << endl;
}
