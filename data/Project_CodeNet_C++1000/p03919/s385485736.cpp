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
using namespace std;
int inf = 1000000000;

int main(void) {

  int h, w;
  cin >> h >> w;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      string s;
      cin >> s;
      char c = 'A' + j;
      if( s == "snuke" ) cout << c << i+1 << endl;
    }
  }

  return 0;
}

// EOF
