#include <bits/stdc++.h>
using namespace std;

int main() {
  long long num;
  long long index = 0;
  long long tmp;
  long long cnt = 0;
  
  cin >> num;
  
  vector<long long> vec(num);
  for(int i = 0; i < num; i++){
    cin >> vec.at(i);
  }
  
  while(index < num){
    if(index == num-1){
      cnt++;
      break;
    }
    
    if(vec.at(index) == vec.at(index+1)){
      index++;
      continue;
    }
    
    if(vec.at(index) > vec.at(index+1)){
      while(index < num-1){
        if(vec.at(index) < vec.at(index+1)){
          break;
        }
        index++;
      }
    }else if(vec.at(index) < vec.at(index+1)){
      while(index < num-1){
        if(vec.at(index) > vec.at(index+1)){
          break;
        }
        index++;
      }
    }
    
    index++;
    cnt++;
  }
  
  cout << cnt;
}
