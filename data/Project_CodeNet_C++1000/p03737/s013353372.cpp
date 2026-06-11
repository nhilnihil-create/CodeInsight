#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s1,s2,s3; cin >> s1 >> s2 >> s3;
  s1[0]-=32;
  s2[0]-=32;
  s3[0]-=32;
  
  cout << s1[0] << s2[0] << s3[0] << endl;
}