#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, x;
  cin >> N >> x;
  if(N == 2){
    cout << (x == 2?"Yes":"No") << endl;
    if(x == 2)for(int i = 0; i < 3; i++)cout << i + 1 << endl;
    return 0;
  } else if(x <= 1|| x >= 2 * N - 1){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<long> ans(2 * N - 1);
  ans.at((2 * N - 1) / 2) = x;
  long co;
  if(x == 2){
    ans.at((2 * N - 1) / 2) = x;
    ans.at((2 * N - 1) / 2 + 1) = x - 1;
    ans.at((2 * N - 1) / 2 + 2) = x + 1;
    ans.at((2 * N - 1) / 2 - 1) = x + 2;
    co = 1;
    for(int i = 0; i < ans.size(); i++){
      while(co == x || co == x - 1|| co == x + 1|| co == x + 2)co++;
      if(ans.at(i) == 0){
        ans.at(i) = co;
        co++;
      }
    }
  } else {
    ans.at((2 * N - 1) / 2) = x;
    ans.at((2 * N - 1) / 2 + 1) = x + 1;
    ans.at((2 * N - 1) / 2 + 2) = 1;
    ans.at((2 * N - 1) / 2 - 1) = 2;
    co = 1;
    for(int i = 0; i < ans.size(); i++){
      while(co == x || co == x + 1|| co == 1|| co == 2)co++;
      if(ans.at(i) == 0){
        ans.at(i) = co;
        co++;
      }
    }
  }
  for(int i = 0; i < ans.size(); i++)cout << ans.at(i) << endl;;
  return 0;
}