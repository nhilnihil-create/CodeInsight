#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin >> s;
  int n = s.size(),i,p = 0;
  for(i=0;i<n;i++){
    if(i%2==0) p -= s[i]=='p';
    else p += s[i]=='g';
  }
  cout << p << "\n";
}