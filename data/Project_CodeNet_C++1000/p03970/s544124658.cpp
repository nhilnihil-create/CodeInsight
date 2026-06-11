#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  string t = "CODEFESTIVAL2016";
  int n = s.length();
  int cnt = 0;
  for (int i=0; i<n; i++) {
    if (s[i] != t[i]) {
      ++cnt;
    }
  }
  cout<<cnt<<endl;

}