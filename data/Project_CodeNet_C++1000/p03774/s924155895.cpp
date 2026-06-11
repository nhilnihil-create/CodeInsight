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

  int N, M;
  cin >> N >> M;

  vector<P> student(N);
  vector<P> check(M);
  vector<int> ans(N);

  for (int i = 0; i < N; i++) {
    cin >> student[i].first >> student[i].second;
  }

  for (int i = 0; i < M; i++) {
    cin >> check[i].first >> check[i].second;
  }

  for (int i = 0; i < N; i++) {
    int p = 51;
    int num = 1e9;
    for (int j = 0; j < M; j++) {
      int dst = abs(student[i].first - check[j].first) + abs(student[i].second - check[j].second);

      // cout << "dst:" << dst << " num:" << num << " P:" << p << endl;

      if(dst < num){
        num = dst;
        p = j+1;
      }
      // cout << "dst:" << dst << " num:" << num << " P:" << p << endl;
      // cout << endl;

    }
    ans.at(i) = p;
  }

  for (int i = 0; i < N; i++) {
    cout << ans.at(i) << endl;
  }

  return 0;
}