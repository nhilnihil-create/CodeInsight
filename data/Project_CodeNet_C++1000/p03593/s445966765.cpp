#include<bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  map<char,int> mp;
  for(int i=0; i<H*W; i++){
    char x;
    cin >> x;
    if(mp.count(x)){
      mp[x]++;
    }
    else{
      mp[x] = 1;
    }
  }
  
  bool flag = true;
  int two = 0;
  int one = 0;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    int x = itr->second;
    if(x %2 != 0){
      one++;
      x--;
    }
    if(x %4 == 0){
      continue;
    }
    else if(x %2 == 0){
      two++;
    }
  }
  
  if(H %2 == 1 && W %2 == 1){
    if(one != 1){
      flag = false;
    }
  }
  else{
    if(one != 0){
      flag = false;
    }
  }
  
  int y = 0;
  if(H %2 == 1){
    y += W/2;
  }
  if(W %2 == 1){
    y += H/2;
  }
  
  if(y < two){
    flag = false;
  }
  
  if(flag){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}