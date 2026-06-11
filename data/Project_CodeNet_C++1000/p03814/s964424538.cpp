#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int l = s.size(), i, j;
  for(i=0; i<l; ++i) if(s[i] == 'A') break;
  for(j=l-1; j>0; --j) if(s[j] == 'Z') break;
  cout << j-i+1 << endl;
}