#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  r(i,4)cout << s.at(i);
  cout << " ";
  for(int i=4;i<s.length();i++)cout << s.at(i);
  cout << endl;
}