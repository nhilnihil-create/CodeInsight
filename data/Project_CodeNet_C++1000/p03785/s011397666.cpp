#include <bits/stdc++.h>

using namespace std;

int main(){

  int N, C, K;
  cin >> N >> C >> K;
  
  int T[N];
  for (int i = 0; i< N; i++) {
    cin >> T[i];
  }
  sort(T, T + N);
  int bus_count = 0;
  int ninzu;
  
  int i = 0;
  while(i < N) {
    bus_count++;
    int bus_time = T[i] + K;
    int j = i;
    ninzu = 0;
    while (j < N && T[j] <= bus_time && ninzu < C) {
      j++;
      ninzu++;
    }
    i = j;
  }

  cout << bus_count << endl;
}