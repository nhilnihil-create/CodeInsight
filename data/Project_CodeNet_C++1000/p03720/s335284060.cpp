//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  int N, M;
  int a, b;
  cin >> N >> M;
  
  int roads[N];
  for(int i = 0; i < N; i++) {
    roads[i] = 0;
  }
  
  for(int i = 0; i < M; i++) {
    cin >> a >> b;
    roads[a - 1]++;
    roads[b - 1]++;
  }
  
  for(int i = 0; i < N; i++){
    cout << roads[i] << endl;
  }
  return 0;
}
