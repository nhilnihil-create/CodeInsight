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
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }

  vector<P> p(9);
  p[0].first = 399;
  p[0].second = 0;
  p[1].first = 799;
  p[1].second = 0;
  p[2].first = 1199;
  p[2].second = 0;
  p[3].first = 1599;
  p[3].second = 0;
  p[4].first = 1999;
  p[4].second = 0;
  p[5].first = 2399;
  p[5].second = 0;
  p[6].first = 2799;
  p[6].second = 0;
  p[7].first = 3199;
  p[7].second = 0;
  p[8].first = 4801;
  p[8].second = 0;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < 9; j++) {
      if(vec.at(i) <= p[j].first){
        p[j].second++;
        break;
      }
    }
  }

  for (int i = 0; i < 8; i++) {
    // cout << p[i].first << " -> "<< p[i].second << endl;
    if(p[i].second > 0) ans++;
  }

  if(ans != 0){
    cout << ans << " " << ans + p[8].second << endl;
  }else{
    cout << 1 << " " << ans + p[8].second << endl;
  }

  return 0;
}