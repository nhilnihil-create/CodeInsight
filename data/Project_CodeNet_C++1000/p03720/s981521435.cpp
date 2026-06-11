#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  
  vector<int> miti(2*M);
  
  for (int i=0; i<2*M; i++) {
    cin >> miti.at(i);
  }
  
  for (int i=0; i<N; i++) {
    int sum=0;
    
    for (int j=0; j<2*M; j++) {
      if (miti.at(j)==i+1) {
        sum++;
      }
    }
    
    cout << sum << endl;
  }
}