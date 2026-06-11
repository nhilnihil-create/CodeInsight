#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  char c=s.at(0);
  int ans=0;
  for(int i=0,l=s.size();i<l;i++){
    if(s.at(i)!=c){
      ans++;
      c=s.at(i);
    }
  }
  cout << ans << endl;
  return 0;
}