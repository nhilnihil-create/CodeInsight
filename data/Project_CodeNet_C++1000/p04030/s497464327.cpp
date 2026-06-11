#include <bits/stdc++.h>
using namespace std;

int main(){

  string s;
  cin >> s;

  string res="";
  int i=0;
  for(auto x:s){
    if (x == 'B'){
      if (res.size()>0)
        res.erase(res.size()-1);
    }
    else
      res += x;
  }
  cout << res << endl;
  
  return 0;
}