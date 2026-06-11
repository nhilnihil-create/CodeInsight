#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  std::string s,code = "CODEFESTIVAL2016";
  int ans=0;
  std::cin >> s;
  for(int i=0;i<16;i++){
    if(s.at(i)!=code.at(i)){
      ans++;
    }
  }
  std::cout << ans;
  return 0;
}