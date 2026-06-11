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
  int N,A,B;
  string S;
  cin >> N >> A >> B >> S;

  int sum=0,sum_B=0;
  string ans;
  for(int i=0;i<N;i++){
    if(S.at(i)=='c') ans="No";
    else if(S.at(i)=='a'){
      if(sum<A+B){
	++sum;
	ans="Yes";
      }
      else ans="No";
    }
    else if(S.at(i)=='b'){
      if(sum<A+B && sum_B<B){
	++sum;
	ans="Yes";
      }
      else ans="No";
      ++sum_B;
    }
    cout << ans << endl;
  }
  

  return 0;
}
