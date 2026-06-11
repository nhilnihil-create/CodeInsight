#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,A,B,C,sum;
  sum = 0;
  cin >> N;
  for (int i=0;i<N;i++) {
    cin >> A >> B;
    C = B-A+1;
    sum += C; 
  }
  cout << sum << endl;
}