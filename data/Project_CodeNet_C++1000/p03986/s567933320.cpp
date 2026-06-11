#include <bits/stdc++.h>
using namespace std;

// 正しいとは限らない括弧列で()を相殺していくと)..)(..(になることと同じ発想
int main(){
  string S;
  cin >> S;


  int cumsum= 0;
  int cs_min= 0;
  for(auto c:S){
    if(c=='S'){ cumsum++; }
    else      { cumsum--; }

    cs_min= min(cs_min, cumsum);
  }
  
  int ans= 2*(0- cs_min);

  cout << ans << endl;
}