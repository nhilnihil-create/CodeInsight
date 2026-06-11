#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define r_rep(i, n) for(int i = n; i >= 0; i--)
#define ll long long int
#define pb push_back

const long long INF = 1LL << 60;

int main() {
  int W, H, N, x, y, a;
  cin >> W >> H >> N;
  int x1 = 0, x2 = W, y1 = 0, y2 = H;
  rep(i, N){
    cin >> x >> y >> a;
    if (a==1) x1 = max(x1, x);
    if (a==2) x2 = min(x2, x);
    if (a==3) y1 = max(y1, y);
    if (a==4) y2 = min(y2, y);
  }

  if(x1 < x2 && y1 < y2) print((x2-x1)*(y2-y1));
  else print(0);
}
