#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  long long N,K;
  cin >> N >> K;
  vector<pair<int, int> > pairs;
  FOR(i,0,N) {
    int a,b;
    cin >> a >> b;
    pairs.push_back({a,b});
  }
  sort(pairs.begin(), pairs.end());
  int x = 0; //最初は一番小さな数
  long long sum = pairs[0].second; //一番小さな数の並びまでは先にカウント
  while(sum < K) {
    x++;
    sum += pairs[x].second;
  }
  cout << pairs[x].first << endl;
  return 0;
}