#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  
  vector<int> pole(N);
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    pole[i] = a;
  }
  
  sort(pole.begin(), pole.end());
  reverse(pole.begin(),pole.end());
  
  int sum_max = 0;
  for(int i=0; i<K; i++) sum_max += pole[i];
  
  cout << sum_max << endl;
    
}