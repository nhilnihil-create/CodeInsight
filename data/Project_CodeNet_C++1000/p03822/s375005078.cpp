//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int N; cin >> N;

  vector <int> graph[N], regraph[N], rest(N);
  for (int i = 1; i < N; i++){
    int A; cin >> A; A--;
    graph[i].push_back(A);
    regraph[A].push_back(i);
    rest[A]++;
  }

  queue <int> que;
  vector <int> depth(N);
  for (int i = 0; i < N; i++){
    if (rest[i] == 0) que.push(i);
  }

  while (!que.empty()){
    int Q = que.front(); que.pop();

    for (int i = 0; i < graph[Q].size(); i++){
      int next = graph[Q][i];
      rest[next]--;
      if (rest[next] == 0) que.push(next);
    }

    if (regraph[Q].size() > 0){
      vector <int> now;
      for (int i = 0; i < regraph[Q].size(); i++){
        int next = regraph[Q][i];
        now.push_back(depth[next]);
      }
      sort(now.begin(), now.end(), greater<int>());

      for (int i = 0; i < now.size(); i++){
        depth[Q] = max(depth[Q], now[i] + i + 1);
      }
    }
  }
  cout << depth[0] << endl;
  
  return 0;
}
