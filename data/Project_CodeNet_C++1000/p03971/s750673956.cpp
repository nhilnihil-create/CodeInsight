#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  bool tuuka[n]={false};
  int a2=0, b2=0;
  for(int i=0; i<n; i++) {
    if(s.at(i)=='a'&&a2+b2<a+b) {
      tuuka[i]=true;
      a2++;
    }
    else if(s.at(i)=='b'&&a2+b2<a+b&&b2<b) {
      tuuka[i]=true;
      b2++;
    }
  }
  for(int i=0; i<n; i++) {
    if(tuuka[i]==true) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
 // cout << a2 << ' ' << b2 << endl;
  return 0;
}