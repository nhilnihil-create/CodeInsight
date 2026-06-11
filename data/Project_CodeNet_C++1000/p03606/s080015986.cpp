#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int l;
  int r;
  int SUM = 0;
  
  cin >> N;
  for (int i = 0; i<N; i++){
    cin >> l >> r; 
    SUM += r - l + 1;
  }
  cout << SUM;
}
