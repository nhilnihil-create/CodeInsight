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

  int A, B, C;
  cin >> A >> B >> C;
  int ans = 0;

  while (1) {
    if(A%2 != 0 || B%2 != 0 || C%2 != 0)break;
    int a = A;
    int b = B;
    int c = C;
    A = (b+c)/2;
    B = (a+c)/2;
    C = (a+b)/2;
    ans++;
    if(A == B && A == C && B == C) {
      ans = -1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}