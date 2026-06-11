#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  ll A,B,C;
  cin >> A >> B >> C;
  ll new_A=A,new_B=B,new_C=C;
  ll ans=0;
  while(1){
    if(new_A%2==1 || new_B%2==1 || new_C%2==1) break;
    ll temp_A=new_A/2, temp_B=new_B/2, temp_C=new_C/2;
    new_A=temp_B+temp_C;
    new_B=temp_C+temp_A;
    new_C=temp_A+temp_B;
    ++ans;
    if(new_A==A && new_B==B && new_C==C){
      ans=-1;
      break;
    }
  }

  cout << ans << endl;
  
  return 0;
}
