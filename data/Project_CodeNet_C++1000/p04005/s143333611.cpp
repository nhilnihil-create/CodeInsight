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

  ll A, B, C, x1, x2, x3;
  cin >> A >> B >> C;

  if(A%2 != 0 && B%2 != 0 && C%2 != 0){
    ll mx = max(A, max(B, C)); // 最大値
    x1 = mx /2;
    x2 = mx /2 + 1;
    ll y;

    if(mx == A){
      y = B*C;
    }else if(mx == B){
      y = A*C;
    }else if(mx == C){
      y = A*B;
    } 

    cout << (x2 * y) - (x1 * y) << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}