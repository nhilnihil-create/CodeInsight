#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  cout << s[0]+to_string(n-2)+s[n-1];
}