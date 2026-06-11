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
#include <utility>

long long dist[204][204];

int main(){
  int N, M, R;
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &R);
  std::vector<int > r(R);
  for (int i=0; i<R; i++){
    scanf("%d", &r[i]);
  }
  std::vector<int > A(M), B(M), C(M);
  std::vector<std::pair<int, int> > edge[204];
  for (int i=0; i<204; i++){
    for (int j=0; j<204; j++){
      dist[i][j]=1e18;
    }
    dist[i][i]=0;
  }
  for (int i=0; i<M; i++){
    scanf("%d", &A[i]);
    scanf("%d", &B[i]);
    scanf("%d", &C[i]);
    edge[A[i]].push_back(std::make_pair(B[i], C[i]));
    edge[B[i]].push_back(std::make_pair(A[i], C[i]));
    dist[A[i]][B[i]]=C[i];
    dist[B[i]][A[i]]=C[i];
  }
  for (int k=1; k<=N; k++){
    for (int i=1; i<=N; i++){
      for (int j=1; j<=N; j++){
	dist[i][j]=std::min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
  /* for (int i=1; i<=N; i++){
    for (int j=1; j<=N; j++){
      printf("dist[%d][%d]=%lld\n", i, j, dist[i][j]);
    }
    }*/
  
  int array[R];
  std::sort(r.begin(), r.end());
  for (int i=0; i<R; i++){
    array[i]=r[i];
  }
  //printf("==========\n");
  long long ans = 1e18;
  do {
    long long d=0;
    bool ng=false;
    for (int i=0; i<R-1; i++){
      //printf("dist[%d][%d]=%lld\n", array[i], array[i+1], dist[array[i]][array[i+1]]);
      d += dist[array[i]][array[i+1]];
    }
    ans = std::min(ans, d);
  } while (std::next_permutation(array, array+R));
  std::cout << ans << std::endl;
  return 0;
}