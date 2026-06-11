#include <bits/stdc++.h>
using namespace std;

int main(void){
  
  string s,t;
  cin >> s;
  cin >> t;
  int all_i = 0,s_i=0,t_i=0;
  int len = s.size() + t.size();
  
  while(1){
      if(all_i %2 == 0){
          cout << s[s_i];
          s_i++;
      }
      else{
          cout << t[t_i];
          t_i++;
      }
      all_i++;
      if(all_i >= len) break;
  }
  cout << endl;
}
