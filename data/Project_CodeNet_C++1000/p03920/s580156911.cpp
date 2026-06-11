#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
typedef long long ll;

int main(){
  int N;
  cin>>N;
  int mxn = 1;
  int sum = 1;
  int nouse = 0;
  while(sum < N)
  {
    mxn++;
    nouse = mxn - (N - sum);
    sum += mxn;
  }
  FOR(i,1,mxn+1)
  {
    if(i==nouse) continue;
    cout << i << endl;
  }
  return 0;
}
