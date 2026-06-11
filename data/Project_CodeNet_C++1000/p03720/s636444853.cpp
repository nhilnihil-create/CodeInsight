#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> toshi(N);
  int left,right;
  
  
  for(int i = 0; i < M; i++){
    cin >> left >> right;
    toshi.at(left - 1)++;
    toshi.at(right - 1)++;
  }
  
  for(int i = 0; i < N; i++){
    cout << toshi.at(i) << endl;
  }
  
  
}