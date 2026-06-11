#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N;
  
  for(int i = 0; i < N; i++){
    int O, P;
    cin >> O >> P;
    A += P - O + 1;
  } 
  cout << A << endl ;
}