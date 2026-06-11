#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  long a=0,b=s.size()-1;
  while(s[a]!='A') a++;
  while(s[b]!='Z') b--;
  cout << b-a+1 << endl;
}