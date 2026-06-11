#include <bits/stdc++.h>
using namespace std;

int main(){
  string S; cin >> S;
  int64_t ans = 0;
 
  
  for(int i=0; i < (1<<S.size()-1); i++){
    bitset<9> plus(i);
    int64_t tmp = S.at(0)-'0';
    
    for (int j=0; j < S.size()-1; j++){
      if(plus.test(j)){
        ans += tmp;
        tmp = 0;
      }
      tmp = tmp*10 + (S.at(j+1) -'0');
    }
    ans += tmp;
  }
  cout << ans << endl;
}