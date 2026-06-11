#include <bits/stdc++.h>
using namespace std;
int main () {
  long N;
  cin >> N;
  string S1, S2;
  cin >> S1 >> S2;
  vector<long> data;
  for(int i = 0; i < S1.size(); i++){
    if(S1.at(i) == S2.at(i)){
      data.push_back(0);
    } else{
      data.push_back(1);
      i++;
    }
  }
  long ans;
  if(data.at(0) == 0)ans = 3;
  else ans = 6;
  for(int i = 1; i < data.size(); i++){
    if(data.at(i - 1) == 0){
      if(data.at(i) == 0)ans *= 2;
      else ans *= 2;
    } else {
      if(data.at(i) == 0)ans *= 1;
      else ans *= 3;
    }
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}