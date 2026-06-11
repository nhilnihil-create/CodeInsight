#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  string s;  cin >> s;
  int l = 0, r = 0;
  for(int i=0; i<n; i++)
    if(s[i] == '(')  r++;
    else
      if(r > 0)  r--;
      else  l++;

  for(int i=0; i<l; i++)  cout << '(';
  cout << s;
  for(int i=0; i<r; i++)  cout << ')';
  cout << endl;

  return 0;
}
