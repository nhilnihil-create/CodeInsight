#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int l[51];
  for (int i = 0; i < N; i++) cin >> l[i];
  
  sort(l, l + N, greater<int>());
  
  int total_length = 0;
  
  for (int i = 0; i < K; i++) total_length += l[i];
  
  cout << total_length << endl;
}