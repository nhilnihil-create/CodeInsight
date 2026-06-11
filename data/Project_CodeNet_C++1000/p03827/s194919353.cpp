#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >>n;
  string s;
  cin >> s;
  int  x = 0, _max = 0;
  for(int i=0;i<n;i++){
    if(s[i] == 'I')x++;
    else if(s[i] == 'D')x--;
    _max = max(_max, x);
  }
  cout<<_max<<"\n";
  return 0;
}