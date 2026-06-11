#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  string S;
  cin >> S;
  
  int N = S.size();
  vector<vector<int>> moji(26);
  
  for (int i = 0; i < 26; i++) {
    moji[i].push_back(-1);
  }
  
  for (int i = 0; i < N; i++) {
    moji[S[i] - 'a'].push_back(i);
  }
  
  
  for (int i = 0; i < 26; i++) {
    moji[i].push_back(N);
  }
  

  
  int ans = 1000;
  for (int i = 0; i < 26; i++) {
    int MAX = 0;
    //それぞれの文字についての最大の間隔を求める
    
    int M = moji[i].size();
    for (int j = 0; j < M-1; j++) {
      MAX = max(MAX, moji[i][j+1]-1-moji[i][j]);
      
    }
    
    ans = min(ans, MAX);

    
  }
  
  cout << ans << endl;
  
}