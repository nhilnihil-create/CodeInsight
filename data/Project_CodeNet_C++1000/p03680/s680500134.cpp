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

  int N, a;
  cin >> N;
  int ans = 0;

  vector<P> p(N);
  for (int i = 0; i < N; i++) {
    cin >> a;
    p[i].first = i+1;
    p[i].second = a;
  }

  int cnt = 0;
  int i = 0;
  while (cnt <= N){
    if(p[i].second == 2){
      cnt++;
      cout << cnt << endl;
      return 0;
    }

    i = p[i].second-1;
    cnt++;
  }

  cout << -1 << endl;

  return 0;
}