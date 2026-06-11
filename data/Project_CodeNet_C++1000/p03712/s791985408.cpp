#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long

using namespace std;
using P = pair<int,int>;

int main(){

  int H, W;
  cin >> H >> W;

  string a;
  vector<string> arr(H);
  for (int i = 0; i < H; i++){
    cin >> a;
    arr.at(i) = a;
  }

  for (int i = 0; i < H+2; i++) {
    for (int j = 0; j < W+2; j++) {
      if((i > 0 && i <= H) && (j > 0 && j <= W)){
        string ans = arr.at(i-1);
        cout << ans[j-1];
      } else {
        cout << "#";
      }
    }
    cout << "" << endl;
  }

  return 0;
}