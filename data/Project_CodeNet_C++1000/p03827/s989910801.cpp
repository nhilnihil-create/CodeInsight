#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int m=0,x=0;
  for(int i=0;i<n;i++){
    if(s.at(i)=='I')
      x++;
    else
      x--;
    if(x>m)
      m=x;
  }
  cout << m;
}