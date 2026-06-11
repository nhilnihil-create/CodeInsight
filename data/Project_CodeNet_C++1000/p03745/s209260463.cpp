#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main(){
  int N, A;
  cin >> N;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> A;
    vec.at(i) = A;
  }

  int status = -1; // -1が同じか切断直後、0が減少、1が増加
  for (int i = 0; i < N-1; i++) {
    if(status == -1){
      if(vec.at(i) < vec.at(i+1)) status = 1;
      if(vec.at(i) > vec.at(i+1)) status = 0;
    }else{
      if(vec.at(i) < vec.at(i+1) && status == 0){ // 減少ステータスのときに増加したらステータスを-1にする
        ans++;
        status = -1;
      }
      if(vec.at(i) > vec.at(i+1) && status == 1){ // 増加ステータスのときに増加したらステータスを-1にする
        ans++;
        status = -1;
      }
    }
  }
  cout << ans+1 << endl;

  return 0;
}