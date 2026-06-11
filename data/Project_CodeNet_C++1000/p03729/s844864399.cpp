#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;
  a = s1.size();
  b = s2.size();
  if(s1[a-1] == s2[0] && s2[b-1] == s3[0]) cout << "YES" << endl;
  else cout << "NO" << endl;
}

