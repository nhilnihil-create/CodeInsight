#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  
  for (int i=0; i<N; i++) {
    cin >> A.at(i);
  }
  
  int sum=0;
  int ima;
  ima = 1;
  
  while (ima != 2) {
    ima = A.at(ima-1);
    sum++;
    if (sum >= N+1) {
      sum = -1;
      break;
    }
  }
  
  cout << sum << endl;
}