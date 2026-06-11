#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int SUM = 0;
  
  int F, L;
  for(int i=0;i<N;i++){
    cin >> F >> L;
    SUM += (L - F + 1);
  }
  cout << SUM << endl;
}