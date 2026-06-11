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
using P = pair<char,int>;

int main(){

  string S;
  cin >> S;
  vector<P> p(4);
  p[0].first = 'N';
  p[0].second = 0;
  p[1].first = 'S';
  p[1].second = 0;
  p[2].first = 'E';
  p[2].second = 0;
  p[3].first = 'W';
  p[3].second = 0;

  for (int i = 0; i < S.size(); i++) {
    if      (S[i] == p[0].first) p[0].second += 1;
    else if (S[i] == p[1].first) p[1].second += 1;
    else if (S[i] == p[2].first) p[2].second += 1;
    else if (S[i] == p[3].first) p[3].second += 1;
  }

  if( (p[0].second > 0 && p[1].second == 0) ||
      (p[1].second > 0 && p[0].second == 0) ||
      (p[2].second > 0 && p[3].second == 0) ||
      (p[3].second > 0 && p[2].second == 0)){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}