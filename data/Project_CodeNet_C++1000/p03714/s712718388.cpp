#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000;
int main(){
  int N;
  cin >> N;
  vector<long long> A(N * 3);
  for (int i = 0; i < N * 3; i++){
    cin >> A[i];
  }
  long long sum = 0;
  vector<long long> L(N * 3, 0);
  priority_queue<long long, vector<long long>, greater<long long>> pq1;
  for (int i = 0; i < N; i++){
    sum += A[i];
    pq1.push(A[i]);
  }
  L[N] = sum;
  for (int i = N; i < N * 2; i++){
    if (pq1.top() < A[i]){
      sum -= pq1.top();
      pq1.pop();
      sum += A[i];
      pq1.push(A[i]);
    }
    L[i + 1] = sum;
  }
  sum = 0;
  vector<long long> R(N * 3, 0);
  priority_queue<long long> pq2;
  for (int i = N * 3 - 1; i >= N * 2; i--){
    sum += A[i];
    pq2.push(A[i]);
  }
  R[N * 2] = sum;
  for (int i = N * 2 - 1; i >= N; i--){
    if (pq2.top() > A[i]){
      sum -= pq2.top();
      pq2.pop();
      sum += A[i];
      pq2.push(A[i]);
    }
    R[i] = sum;
  }
  long long ans = -INF;
  for (int i = N; i <= N * 2; i++){
    ans = max(ans, L[i] - R[i]);
  }
  cout << ans << endl;
}