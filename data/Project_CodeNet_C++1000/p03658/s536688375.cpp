#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  int t = 0;
  vector<int> vec(N);
  for(int i = 0;i < N;++i) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  for(int i = 0;i < M;++i) {
    t = t + vec.at(i); 
  }
  cout << t << endl;
}