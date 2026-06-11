#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  long long sum = 0;
  for (int i = 0; i < n - 1; i++){
    if (a[i + 1] > a[i]){
      sum += a[i + 1] - a[i];
    } else {
      sum += m - (a[i] - a[i + 1]);
    }
  }
  vector<int> A(m + 1, 0);
  vector<long long> B(m + 1, 0);
  for (int i = 0; i < n - 1; i++){
    if (a[i + 1] > a[i]){
      A[a[i] + 1]++;
      A[a[i + 1] + 1]--;
      B[a[i] + 1] -= a[i] + 1;
      B[a[i + 1] + 1] += a[i] + 1;
    } else {
      A[a[i] + 1]++;
      A[m]--;
      B[a[i] + 1] -= a[i] + 1;
      B[m] += a[i] + 1;
      A[0]++;
      A[a[i + 1] + 1]--;
      B[0] += m - a[i] - 1;
      B[a[i + 1] + 1] -= m - a[i] - 1;
    }
  }
  for (int i = 1; i <= m; i++){
    A[i] += A[i - 1];
    B[i] += B[i - 1];
  }
  vector<long long> C(m);
  for (int i = 0; i < m; i++){
    C[i] = (long long) A[i] * i + B[i];
  }
  long long mx = 0;
  for (int i = 0; i < m; i++){
    mx = max(mx, C[i]);
  }
  cout << sum - mx << endl;
}