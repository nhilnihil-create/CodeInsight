#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,M;
  cin >> N >> M;
  
  vector<int>x(M);
  vector<int>y(M);
  vector<int>a(N,1);
  vector<int>b(N,0);
  b.at(0) = 1;
  for (int i = 0; i < M; i++) {
    cin >> x.at(i) >> y.at(i);
    if (b.at(x.at(i)-1) == 1){
      if (a.at(x.at(i)-1) == 1){
        b.at(x.at(i)-1) = 0;
      }
      b.at(y.at(i)-1) = 1;
    }
    a.at(x.at(i)-1)--;
    a.at(y.at(i)-1)++;
  }
  
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (b.at(i) == 1){
      count++;
    }
  }
  cout << count << endl;
}
  
  
    