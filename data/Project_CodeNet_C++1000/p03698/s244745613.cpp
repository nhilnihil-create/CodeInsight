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
#include <set>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;

  set<char> include;
  for(int i=0;i<S.size();i++){
    if(include.count(S.at(i))){
      cout << "no" << endl;
      return 0;
    }
    else{
      include.insert(S.at(i));
    }
  }

  cout << "yes" << endl;

  return 0;
}
