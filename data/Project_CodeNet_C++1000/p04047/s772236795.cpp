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

int main(){

  int N, l;
  cin >> N;
  int ans = 0;
  vector<int> vec(N*2);

  for (int i = 0; i < N*2; i++){
    cin >> l;
    vec.at(i) = l;
  }
  sort(vec.begin(), vec.end());

  int cnt = N*2;
  while (cnt > 1){
    ans += min(vec.at(cnt-1), vec.at(cnt-2));
    cnt -= 2;
  }

  cout << ans << endl;

  return 0;
}