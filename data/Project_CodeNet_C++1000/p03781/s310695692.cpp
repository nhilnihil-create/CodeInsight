#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <limits>
#include <stack>

using namespace std;

int main(){
  long X;
  cin >> X;
  for(int i=1;i<=X;++i){
    if(X<=i*(i+1)/2){
       cout << i << endl;
       break;
    }
  }
  return 0;
}