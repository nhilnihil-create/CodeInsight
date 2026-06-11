#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> T(N);
  for ( int i = 0; i < N ; i++ ){
    cin >> T.at(i);
  }
  
  int M;
  cin >> M;
  vector <vector <int>> P(M, vector<int>(2));
  for ( int i = 0 ; i < M ; i++ ){
    for ( int  j = 0 ; j < 2 ; j++ ){
      cin >> P.at(i).at(j);
    }
  }
  
  int count;
  for (int i = 0 ; i < M ; i++ ){
    int w = T.at(P.at(i).at(0) - 1);
    T.at(P.at(i).at(0) - 1) = P.at(i).at(1);
    for ( int j = 0; j < N ; j++ ){
      count = count + T.at(j);
    }
    cout << count << endl;
    count = 0;
    T.at(P.at(i).at(0) - 1) = w;
  }
}