#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
using namespace std;
int mod = 1e9+7;

int main() {

  int n;
  cin >> n;

  for(int i=1; i<=n; i++){
    int tmp = i * (i+1) / 2;
    if( tmp >= n ){
      for(int j=1; j<=i; j++){
        if( j == tmp - n ) continue;
        cout << j << endl;
      }
      return 0;
    }
  }

  return 0;
}

//
