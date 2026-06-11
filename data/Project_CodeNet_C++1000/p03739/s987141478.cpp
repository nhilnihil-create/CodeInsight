#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n;i++) cin >> v.at(i);
  //1番目を正にする場合
  int64_t sum1 = 0,ans1 = 0;
  for(int i = 0; i < n; i++){
    sum1 += v.at(i);
    if(i % 2 == 0){
      if(sum1 <= 0) {
        ans1 += 1-sum1;
        sum1 += 1-sum1;
      }
    }else {
      if(sum1 >= 0) {
        ans1 += 1 + sum1;
        sum1 -= 1 + sum1;
      }
    }
  }
  //1番目を負にする場合
  int64_t sum2 = 0,ans2 = 0;
  for(int i = 0; i < n; i++){
    sum2 += v.at(i);
    if(i % 2 == 0){
      if(sum2 >= 0) {
        ans2 += 1+sum2;
        sum2 -= 1+sum2;
      }
    }else {
      if(sum2 <= 0) {
        ans2 += 1 - sum2;
        sum2 += 1 - sum2;
      }
    }
  }
  cout << min(ans1,ans2) << endl;
}