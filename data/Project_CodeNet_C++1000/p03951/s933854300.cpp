#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s, t;
  cin >> n >> s >> t;
  
  string ans = s;
  int start = 1000;
  for(int i = 0; i < n; i++){
    char x = s.at(i);
    if(x == t.at(0)){
      bool ok = true;
      int ti = 0;
      for(int j = i; j < n; j++){
        if(ti >= n) break;
        if(s.at(j) != t.at(ti)) ok = false;
        ti++;
      }
      if(ok){
        start = i;
        break;
      }
    }
  }
  
  for(int i = 0; i < n; i++){
    if(start < n) ans.at(start) = t.at(i);
    else ans.push_back(t.at(i));
    start++;
  }
  
  cout << ans.size() << endl;
}