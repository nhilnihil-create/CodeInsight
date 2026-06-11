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
  int H,W;
  cin >> H >> W;
  vector<string> a(H);

  for(int i=0;i<H;++i) cin >> a.at(i);

  for(int i=0;i<W+2;++i) cout << '#';
  cout << endl;
  for(int i=0;i<H;++i) cout << '#' << a.at(i) << '#' << endl;
  for(int i=0;i<W+2;++i) cout << '#';
  cout << endl;

  return 0;
}
