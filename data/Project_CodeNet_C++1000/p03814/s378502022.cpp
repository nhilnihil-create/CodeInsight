#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int m=0,n=s.size()-1;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='A')
      break;
    m++;
  }
  for(int i=0;i<s.size();i++){
    if(s.at(n)=='Z')
      break;
    n--;
  }
  cout << n-m+1 << endl;
}