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
#define ll long long int
#define pb push_back

const long long INF = 1LL << 60;

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (a <= b &&  b - (a+w) <= 0) print(0);
  else if (a > b && a - (b+w) <= 0) print(0);
  else print( min(abs((a+w) - b), abs((b+w) - a)) );

}
