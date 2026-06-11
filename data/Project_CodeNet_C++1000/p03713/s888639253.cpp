#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t H, W;
  cin >> H >> W;
  int64_t x = H/3;
  int64_t ans = 1000000;
  
  if(H %3 == 0 || W %3 == 0){
    ans = 0;
  }
  else{
    ans = min(H,W);
  }
  
  vector<int64_t> vec(3);
  for(int i=0; i<=3; i++){
    vec.at(0) = (x+i)*W;
    vec.at(1) = (H-x-i)*(W/2);
    vec.at(2) = H*W - vec.at(1) - vec.at(0);
    sort(vec.begin(),vec.end());
    ans = min(ans,vec.at(2)- vec.at(0));
  }
  swap(H,W);
  x = H/3;
  for(int i=0; i<=3; i++){
    vec.at(0) = (x+i)*W;
    vec.at(1) = (H-x-i)*(W/2);
    vec.at(2) = H*W - vec.at(1) - vec.at(0);
    sort(vec.begin(),vec.end());
    ans = min(ans,vec.at(2)- vec.at(0));
  }
  cout << ans << endl;
}