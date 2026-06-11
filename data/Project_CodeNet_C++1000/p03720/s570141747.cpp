#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  vector<int> ans(N,0);

  for (int i =0 ; i < M ; i++){
    cin >> a.at(i);
    cin >> b.at(i);
  }
  //ここまで入力
  

  for (int i = 0; i <N; i++){
      for (int j =0; j < M; j++){
          if(a.at(j)==i+1){
              ans.at(i)++;
          }
          if(b.at(j)==i+1){
              ans.at(i)++;
          }
      }
      cout << ans.at(i) << endl;
  }
}
