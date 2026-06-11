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
  string A,B;
  cin >> A >> B;
  if(A.size()>B.size()){
    cout << "GREATER" << endl;
    return 0;
  }
  else if(A.size()<B.size()){
    cout << "LESS" << endl;
    return 0;
  }
  else if(A.size()==B.size()){
    for(int i=0;i<A.size();++i){
      if(A.at(i)==B.at(i)) continue;
      if(A.at(i)>B.at(i)){
	cout << "GREATER" << endl;
	return 0;
      }
      else{
	cout << "LESS" << endl;
	return 0;
      }
    }
  }

  cout << "EQUAL" << endl;

  return 0;
}
