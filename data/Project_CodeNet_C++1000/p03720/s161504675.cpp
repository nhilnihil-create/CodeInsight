#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  
  int Answer;
  
  vector<int> road(2*M);
  
  for (int i=0; i<2*M; i++){
    cin >> road.at(i);
  }
  
  for (int i=0; i<N; i++){
    Answer = 0;
    for (int j=0; j<2*M; j++){
      if(road.at(j) == i+1) Answer ++;
    }
    cout << Answer << endl;
  }
}
