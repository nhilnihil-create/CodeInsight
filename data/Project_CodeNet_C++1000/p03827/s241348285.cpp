#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string s;
  cin>>s;
  int x=0;
  int saidai=0;
  for(int i=0;i<n;i++){
    if(s[i]=='I')x++;
    else x--;
    saidai=max(saidai,x);
  }
  cout<<saidai<<endl;
  return 0;
}