#include <bits/stdc++.h>
using namespace std;


int main() {
  int num;
  int tmp;
  int cnt = 0;
  vector<int> vec(9,0);
  
  cin >> num;
  
  for(int i = 0; i < num; i++){
    cin >> tmp;
    if(tmp <=399) vec.at(0) = 1;
    if(tmp >= 400 && tmp <= 799) vec.at(1) = 1;
    if(tmp >= 800 && tmp <= 1199) vec.at(2) = 1;
    if(tmp >= 1200 && tmp <= 1599) vec.at(3) = 1;
    if(tmp >= 1600 && tmp <= 1999) vec.at(4) = 1;
    if(tmp >= 2000 && tmp <= 2399) vec.at(5) = 1;
    if(tmp >= 2400 && tmp <= 2799) vec.at(6) = 1;
    if(tmp >= 2800 && tmp <= 3199) vec.at(7) = 1;
    if(tmp >= 3200) vec.at(8) += 1;
  }
  
  for(int i = 0; i < 8; i++){
    if(vec.at(i) == 1) cnt++;
  }
  
  // Min
  if(cnt == 0 && vec.at(8) >= 1){
    cout << 1 << " ";
  }else{
    cout << cnt << " ";
  }
  
  // Max
  if(vec.at(8) >= 1){
    cnt = vec.at(8) + cnt;
  }
  
  cout << cnt;
}
