#include<bits/stdc++.h>
using namespace std;

int main(){
  int cntN=0;
  int cntW=0;
  int cntS=0;
  int cntE=0;
  string str;
  bool chk = true;
  
  cin >> str;
  
  for(int i = 0; i < str.size(); i++){
    if(str.at(i) == 'N') cntN++;
    else if(str.at(i) == 'W') cntW++;
    else if(str.at(i) == 'S') cntS++;
    else cntE++;
  }
  
  if((cntN > 0 && cntS == 0) || (cntN == 0 && cntS > 0)){
    chk = false;
  }
  if((cntE > 0 && cntW == 0) || (cntE == 0 && cntW > 0)){
    chk = false;
  }
  
  if(chk == true) cout << "Yes";
  else cout << "No";
  
}