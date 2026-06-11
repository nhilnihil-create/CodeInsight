#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> road(2 * M);
  vector<int> town(N);
  for(int i = 0; i < 2 * M; i++) {
    cin >> road.at(i);
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 2 * M; j++) {
      if(road.at(j) == i + 1) {
        town.at(i)++;
      }
    }
    cout << town.at(i) << endl;
  }
}