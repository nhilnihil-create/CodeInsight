#include <iostream>
#include <string>

using lli=long long;
const int mod=1000000007;

int main(){
  int N;
  std::cin >> N;

  std::string S1,S2;
  std::cin >> S1 >> S2;

  lli ans = 0;
  bool prev_v = false;
  for(int i = 0; i < N; i++){
    if(S1[i] == S2[i]){
      if(i == 0) ans = 3;
      else if(prev_v) ans *= 2;
      prev_v = true;
    }else{
      if(i == 0) ans = 6;
      else if(prev_v) ans *= 2;
      else ans *= 3;
      prev_v = false;
      i++;
    }
    ans %= mod;
  }
  std::cout << ans << std::endl;

  return 0;
}

