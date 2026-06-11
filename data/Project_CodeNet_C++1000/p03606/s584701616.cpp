#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int N;
  cin >> N;
  vector<vector<int>> h(N,vector<int> (2));
  for(int i =0;i<N;i++){
    cin >> h.at(i).at(0) >> h.at(i).at(1);
  }
  int sum = 0;
  for(int i = 0; i<N; i++){
    sum +=h.at(i).at(1)-h.at(i).at(0)+1;
  }
  cout << sum << endl;
}