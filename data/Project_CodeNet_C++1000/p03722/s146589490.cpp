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
#include <deque>
#include <set>
#include <stack>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  int N, M; cin >> N >> M;

  vector <int> G1[N], G2[N];
  vector < pair<ll, int> > graph[N];

  for (int i = 0; i < M; i++){
    int A, B; ll C; cin >> A >> B >> C;
    A--; B--; C = -1 * C;
    G1[A].push_back(B);
    G2[B].push_back(A);
    graph[A].push_back(make_pair(C, B));
  }
  
  vector <bool> C1(N), C2(N);
  queue <int> que1, que2;

  que1.push(0); C1[0] = true;
  while (!que1.empty()){
    int Q = que1.front(); que1.pop();
    for (int i = 0; i < G1[Q].size(); i++){
      int next = G1[Q][i];
      if (C1[next] == false){
        C1[next] = true;
        que1.push(next);
      }
    }
  }

  que2.push(N - 1); C2[N - 1] = true;
  while (!que2.empty()){
    int Q = que2.front(); que2.pop();
    for (int i = 0; i < G2[Q].size(); i++){
      int next = G2[Q][i];
      if (C2[next] == false){
        C2[next] = true;
        que2.push(next);
      }
    }
  }

  bool flag = false;
  vector <ll> dist(N);
  fill(dist.begin() + 1, dist.end(), 1e16);

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      for (int k = 0; k < graph[j].size(); k++){
        ll cost = graph[j][k].first;
        int next = graph[j][k].second;

        if (dist[j] != 1e16 && dist[next] > dist[j] + cost){
          dist[next] = dist[j] + cost;
          if (i == N - 1 && C1[j] == true && C2[next] == true){
            flag = true;
          }
        }
      } 
    }
  }
  
  if (flag == true){
    cout << "inf" << endl;
  }else{
    cout << -1 * dist[N - 1] << endl;
  }
  
  return 0;
}