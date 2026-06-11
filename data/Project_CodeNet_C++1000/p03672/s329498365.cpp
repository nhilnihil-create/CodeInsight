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
  string S;
  cin >> S;
  int n=S.size();

  for(int i=n-1;i>0;--i){
    string sub_s=S.substr(0,i);
    int size=sub_s.size();
    if(size%2==1) continue;
    string first=sub_s.substr(0,size/2);
    string second=sub_s.substr(size/2,size/2);
    if(first==second){
      cout << size << endl;
      break;
    }
  }
  

  return 0;
}
