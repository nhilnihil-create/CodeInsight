#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N, M;
  cin >> N >> M;
  vector<int> road(N, 0);
  int r;
  
  for (int i = 0; i < 2*M ; i++) {
    cin >> r;
    road.at(r-1)++;
  }
  
    for (int i = 0; i < N; i++) {
    cout << road.at(i) << endl;
  }
  
}