#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>>ab(2, vector<int>(N));
  vector<vector<int>>cd(2, vector<int>(M));
  for(int i=0; i<N; i++)cin >> ab.at(0).at(i) >> ab.at(1).at(i);
  for(int i=0; i<M; i++)cin >> cd.at(0).at(i) >> cd.at(1).at(i);
  
  
  for(int i=0; i<N; i++){
    int kyori = 1000000000;
    int kyori2;
    int tika = 0;
    int X = ab.at(0).at(i);
    int Y = ab.at(1).at(i);
    
    for(int j=0; j<M; j++){
      kyori2 = max(cd.at(0).at(j), X) - min(cd.at(0).at(j), X) + max(cd.at(1).at(j), Y) - min(cd.at(1).at(j), Y);
      if(kyori2<kyori){
        kyori = kyori2;
        tika = j+1;
      }
    }
    cout << tika << endl;
  }
}