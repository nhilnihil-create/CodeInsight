#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> v(2 * M);
 
  for (int i = 0; i < N; i++) {
    int C = 0;
    for (int j = 0; j < M; j++) {
       cin >> v.at(2 * j) >>v.at(2 * j + 1);
 
      if (v.at(2 * j) == i + 1 || v.at(2 * j + 1) == i + 1) {
        C = C + 1;
      }
    }    
    cout << C << endl;
  }
}
   