#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>

struct edge {
  int dst;
  long long cost;
};

int main(){
  int N;
  scanf("%d", &N);
  int a, b, c;
  std::vector<edge > edges[N];
  for (int i=0; i<N-1; i++){
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    a--;
    b--;
    struct edge thisedge = {b, (long long)c};
    edges[a].push_back(thisedge);
    thisedge.dst = a;
    edges[b].push_back(thisedge);
  }
  int Q, K;
  scanf("%d", &Q);
  scanf("%d", &K);
  K--;
  std::vector<int > x(Q), y(Q);
  for (int i=0; i<Q; i++){
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
    x[i]--;
    y[i]--;
  }
  std::priority_queue<int > queue;
  queue.push(K);
  std::vector<long long > dist(N+4, 1e15);
  dist[K]=0;
  while(queue.size()>0){
    int src = queue.top();
    queue.pop();
    for (int i=0; i<edges[src].size(); i++){
      int dst = edges[src][i].dst;
      if (dist[dst]>dist[src]+edges[src][i].cost){
        dist[dst] = dist[src]+edges[src][i].cost;
        queue.push(dst);
      }
    }
  }

  for (int i=0; i<Q; i++){
    printf("%lld\n", dist[x[i]]+dist[y[i]]);
  }
  return 0;
}
