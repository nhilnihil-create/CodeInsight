#include <bits/stdc++.h>
using namespace std;

int main () {
  string N;
  cin >> N;
  
  int64_t n= N.size(),ans=0;
  
  for (int tmp = 0; tmp < (1 << (n-1)); tmp++) {
    bitset<12> s(tmp); 
    
    int64_t sum = 0,t=N.at(0)-'0';
    
    for (int i = 0; i < n-1; i++) {
      if (s.test(i)) {
        t = (t*10)+N.at(i+1)-'0';
        
      }else{
        sum+=t;
        t=N.at(i+1)-'0';
      }
    }
    ans +=(sum+t);
  }
  cout << ans << endl;
}