#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector <vector <int> > students (N, vector<int>(2));
  for (int i = 0; i < N ; i++ ){
    for (int j = 0 ; j < 2 ; j++){
      cin >> students.at(i).at(j);
    }
  }
  
  vector <vector <int> > checkpoints (M, vector<int>(2));
  for (int i = 0; i < M ; i++ ){
    for (int j = 0 ; j < 2 ; j++){
      cin >> checkpoints.at(i).at(j);
    }
  }
    
  int X, Y;
  X = 999999999;
  for (int i = 0 ; i < N ; i++){
    for (int j = 0; j < M ; j++ ){
      int x = 0;
      x = abs(students[i][0] - checkpoints[j][0]) 
        + abs(students[i][1] - checkpoints[j][1]);
      if (x < X){ Y = j + 1 ; }
      X = min (x, X);
//      cout << x << " " << X << " " << Y <<endl;
    }
    cout << Y << endl;
    Y = 0;
    X = 999999999;
  }
}