#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>T(N);
  for(int i=0; i<N; i++)cin >> T.at(i);
  int M;
  cin >> M;
  vector<vector<int>>PX(M, vector<int>(2));
  for(int i=0; i<M; i++)cin >> PX.at(i).at(0) >> PX.at(i).at(1);
  
  int goukei=0;
  for(int i=0; i<N; i++)goukei += T.at(i);
  
  for(int i=0; i<M; i++){
    cout << goukei -T.at(PX.at(i).at(0)-1) + PX.at(i).at(1) << endl;
  }
  
}