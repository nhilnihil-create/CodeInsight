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

  for (int i = 0; i < N; i++) {
    int s = p[i].second;    
    if(p[i].first == p[s-1].second) ans++;
  }

  cout << ans/2 << endl;

  return 0;
}