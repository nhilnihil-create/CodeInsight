#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<int>a(N);
  vector<int>count(9,0);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
    if (a.at(i) >= 3200){
      count.at(8)++;
    }
    else {
      count.at(a.at(i)/400)++;
    }
  }
  
  int M = 0;
  for (int i = 0; i < 8; i++) {
    if (count.at(i) > 0){
      M++;
    }
  }
  
  cout << max(M,1) << ' ' << M+count.at(8) << endl;
}