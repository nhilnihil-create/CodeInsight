#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  
  int cost = 10000000;
  for (int i = -100; i <= 100; i++) {
    int sum = 0;
    
    for (int j = 0; j < N; j++) {
      sum += abs(i - a[j]) * abs(i - a[j]);
    }
    
    if (cost > sum) {
      cost = sum;
    }
  }
  
  cout << cost << endl;
}