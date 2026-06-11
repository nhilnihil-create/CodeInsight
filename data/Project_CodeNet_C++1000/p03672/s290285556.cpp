#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n=s.size()/2;
  int ans=0;
  for(int i=0;i<n;i++){
    int x=1;
    for(int j=0;j<i;j++){
      x*=(s.at(i+j)==s.at(j));
    }
    if(x) ans=i;
  }
  cout << 2*ans << endl;
}