#include <bits/stdc++.h>
using namespace std;
int main () {
  int N, M, K;
  cin >> N >> M >> K;
  long count, sub;
  for(int i = 0; i <= N; i++){
    count = 0;
    count += M * i;
    for(int j = 0; j <= M; j++){
      sub = count;
      sub -= i * j;
      sub += (N - i) * j;
      if(sub == K){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
