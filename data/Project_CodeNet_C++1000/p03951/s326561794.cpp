#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s, t;
  cin >> s >> t;
  
  int res = 10000000;
  for (int i = 0; i < N; i++){
    bool flag = false;
    for (int j = 0; j < N; j++){
      if (i + j >= N){
        res = min(i + N, res);
        break;
      }
      if (s[i + j] != t[j]) {
        flag = true;
        break;
      }
    }
    if (flag == false) res = min(i + N, res);
  }
  if (res == 10000000) res = N * 2;
  
  cout << res << endl;
}
