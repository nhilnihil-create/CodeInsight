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

  int N;
  string s, t;
  cin >> N >> s >> t;

  for (int i = 0; i < N; i++) {
    string ss = s;
    ss = ss.substr(i,s.size());

    string tt = t;
    tt = tt.substr(0,s.size()-i);

    if(ss == tt){
      cout << N*2 - ss.size() << endl;
      return 0;
    }
  }

  cout << s.size()+t.size() << endl;

  return 0;
}