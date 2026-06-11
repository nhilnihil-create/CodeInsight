#include<bits/stdc++.h>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  int a = s.size(),b;
  for(int i=0;i<a;i=i+2) {
    cout << s[i];
  }
}