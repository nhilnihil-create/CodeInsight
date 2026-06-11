#include <bits/stdc++.h>
using namespace std;
bool possible(vector<queue<int>> A, int k){
  int N = A.size();
  int M = A[0].size();
  vector<bool> use(M, true);
  for (int i = 0; i < M - 1; i++){
    map<int, int> freq;
    int next = -1;
    for (int j = 0; j < N; j++){
      while (!use[A[j].front()]){
        A[j].pop();
      }
      freq[A[j].front()]++;
      if (freq[A[j].front()] > k){
        next = A[j].front();
      }
    }
    if (next == -1){
      return true;
    } else {
      use[next] = false;
    }
  }
  return false;
}
int main(){
  int N, M;
  cin >> N >> M;
  vector<queue<int>> A(N);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      int a;
      cin >> a;
      a--;
      A[i].push(a);
    }
  }
  int tv = N;
  int fv = 0;
  while (tv - fv > 1){
    int mv = (tv + fv) / 2;
    if (possible(A, mv)){
      tv = mv;
    } else {
      fv = mv;
    }
  }
  cout << tv << endl;
}