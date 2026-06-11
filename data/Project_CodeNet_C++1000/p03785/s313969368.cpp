#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long N, C, K;
  cin >> N >> C >> K;
  long long time = 0;
  long long ninzu = 0;
  long long count = 0;
  long long T[N];
  for (int i = 0; i < N; i++) cin >> T[i];
  sort(T, T + N);
  for (long long i = 0; i < N; i++){
    if (ninzu == 0){
      time = T[i];
      ninzu++;
    }
    else {
      ninzu++;
    }
    if (T[i] > time + K){
      time = T[i];
      count++;
      ninzu = 1;
    }
    else if (ninzu == C){
      ninzu = 0;
      count++;
    }
  }
  if (ninzu >= 1) count++;
  
  cout << count << endl;
}