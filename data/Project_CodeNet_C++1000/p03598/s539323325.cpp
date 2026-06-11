#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  for(int i=0; i<N; i++)
    cin >> x[i];
  int g=0;
  
  for(int j=0; j<N; j++) {
    if(K-x[j]<x[j]) 
      g += (K-x[j])*2;
    else
      g += x[j]*2;
  }
  
  cout << g << endl;
}