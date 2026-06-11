#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
   int N;
   cin >> N ;
 
   vector<int> T(N);
   for (int i = 0; i < N; i++) {
     cin >> T.at(i);
   } 
  
   int M;
   cin >> M;
  // int型の2次元配列(M×2要素の)の宣言
  vector<vector<int>> P(M, vector<int>(2));
 
  // 入力 (2重ループを用いる)
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> P.at(i).at(j);
    }
  }
  
  for (int i = 0; i < M; i++) {
    int total = 0; //合計
    int count = 0; // カウンタ変数
    while (count < N) {
      if (count == P.at(i).at(0)-1) {
        total += P.at(i).at(1);        
      }
      else {
        total += T.at(count);  
      }
      count++;
    } 
    
    cout << total << endl;   
  } 
}