#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
/* 大文字を小文字に変換 tolower*/
/* 小文字を大文字に変換 toupper*/
 
int main () {
int a,b,c,d;
  cin >> a >> b >>c >>d;
  int ma = a *b;
  ma = max (ma,c*d);
  cout << ma << endl;
}