#include <bits/stdc++.h>
using namespace std;

long long pattern_sum(string &S, int order, vector<bool> plus){
  if (order == S.size()){
    int start = 0, length = 0, sum = 0;
    for (int i=0; i<S.size(); i++){
      if (!(plus.at(i))) length++;
      else{
        sum += stoi(S.substr(start, length));
        start = i;
        length = 1;
      }
      if (length == S.size() && length > 1){
        return stoi(S.substr(0,1))*pow(10, length-1) + stoi(S.substr(1));
      }else if (length == S.size() && length == 1){
        return stoi(S.substr(0,1));
      }
      if (i == S.size()-1){
        sum += stoi(S.substr(start));
      }
    }
    return sum;
  }
  
  long long ans=0;
  for (int i=0; i<2; i++){
    plus.at(order) = i==0 ? false : true;
    ans += pattern_sum(S, order+1, plus);
  }
  return ans;
}

int main() {
  string S;
  cin >> S;
  
  vector<bool> plus(S.size());
  plus.at(0) = false;
  
  cout << pattern_sum(S, 1, plus) << endl;
  
}
