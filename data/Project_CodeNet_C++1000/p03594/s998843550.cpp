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
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int ,int> P;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int H, W, d; cin >> H >> W >> d;
  string col = "YBRG";
  FOR(i,0,H) {
    FOR(j,0,W) {
      int x = ((i + j) % (2 * d) + 2 * d) % (2 * d) / d;
      int y = ((i - j) % (2 * d) + 2 * d) % (2 * d) / d;
      cout << col[2 * x + y];
    }
    cout << '\n';
  }
  return 0;
}