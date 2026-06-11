#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, K, x[110];
  cin >> N >> K;
  for(int i = 0; i < N; ++i) cin >> x[i];
  
  int dist = 0;
  for(int i = 0; i < N; ++i)
  {
    dist += min(x[i], abs(x[i]-K)) * 2;
  }
  
  cout << dist << endl;
}