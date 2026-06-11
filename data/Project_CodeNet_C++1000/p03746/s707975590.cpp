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

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  int N, M; cin >> N >> M;
  vector <int> graph[N];

  for (int i = 0; i < M; i++){
    int A, B; cin >> A >> B;
    A--; B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  
  deque <int> dq{0, graph[0][0]};
  vector <bool> visited(N);

  visited[0] = true; visited[graph[0][0]] = true;

  while (true){
    bool flag = true;
    int now = dq.front();
    for (int i = 0; i < graph[now].size(); i++){
      int next = graph[now][i];
      if (visited[next] == false){
        visited[next] = true;
        flag = false;
        dq.push_front(next);
        break;
      }
    }
    if (flag == true) break;
  }
  
  while (true){
    bool flag = true;
    int now = dq.back();
    for (int i = 0; i < graph[now].size(); i++){
      int next = graph[now][i];
      if (visited[next] == false){
        visited[next] = true;
        flag = false;
        dq.push_back(next);
        break;
      }
    }
    if (flag == true) break;
  }
  
  cout << dq.size() << endl;
  while (!dq.empty()){
    cout << dq.front() + 1;
    dq.pop_front();

    if (dq.empty()) cout << endl;
    else cout << " ";
  }

  
  return 0;
}
