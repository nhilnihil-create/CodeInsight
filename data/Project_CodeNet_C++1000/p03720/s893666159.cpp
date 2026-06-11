#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(M), b(M);
  for(int i = 0; i < M; i++) {
    cin >> a.at(i) >> b.at(i);
  }

  int city = 0;
  for(city = 0; city < N; city++) {
    int count  = 0;
    for(int i = 0; i < M; i++) {
      if(a.at(i) == city + 1) {
        count++;
      }
      if(b.at(i) == city + 1) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}