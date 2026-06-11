#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
  }
  int avg = round(float(sum) / N);
  
  int cost = 0;
  for (int i = 0; i < N; i++) {
    cost += pow(a[i] - avg, 2);
  }
  
  cout << cost << endl;
  return 0;
}