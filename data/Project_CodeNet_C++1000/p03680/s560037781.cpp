#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N ;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a.at(i);
  }
  int now = 0;
  for (int i = 0; i < N; i++){
    if(now == 1){
      cout << i << endl;
      break;
    }else if(i == N - 1){
      cout << -1 << endl;
    }
    now = a.at(now) - 1;
  }
}