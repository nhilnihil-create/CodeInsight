#include <bits/stdc++.h>
using namespace std;

int x(int a){
  if(a>0) return 1;
  else return 0;
}

int main(){
  string s;
  cin >> s;
  int N=0,W=0,S=0,E=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='N') N++;
    if(s.at(i)=='W') W++;
    if(s.at(i)=='S') S++;
    if(s.at(i)=='E') E++;
  }
  int ans=1;
  ans*=((x(N)+x(S)+1)%2);
  ans*=((x(W)+x(E)+1)%2);
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}