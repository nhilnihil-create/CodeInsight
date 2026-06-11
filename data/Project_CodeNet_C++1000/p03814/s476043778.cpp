#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.length();
  int i=0;
  while (s[i]!='A') i++;
  int j=n-1;
  while (s[j]!='Z') j--;
  cout<<j-i+1<<endl;
  return 0;
}