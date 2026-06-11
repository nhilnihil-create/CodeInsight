#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> count(N);
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    count[a]++;
    count[b]++;
  }
  bool flg = true;
  for (int i = 0; i < N; i++){
    if (count[i] % 2 == 1){
      flg = false;
    }
  }
  cout << (flg ? "YES" : "NO");
}