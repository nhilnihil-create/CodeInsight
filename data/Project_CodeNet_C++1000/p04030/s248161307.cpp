#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, ans;
  cin >> s;
  
  for(int i = 0; i < s.size(); i++){
    if(s.at(i) == '0'){
      ans = ans + '0';
    }
    
    else if(s.at(i) == '1'){
      ans = ans + '1';
    }
    
    else if(s.at(i) == 'B'){
      if(ans.empty() == false){
        ans.pop_back();
      }
    }
  }
  
  cout << ans << endl;
}
