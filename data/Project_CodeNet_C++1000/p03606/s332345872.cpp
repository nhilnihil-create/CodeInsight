#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum=0;
  cin >> N;
  int L[N],R[N];
  
  for(int i=0; i<N; i++) {
    cin >> L[i]>> R[i];
    sum += R[i] - L[i] + 1;
  }
  cout << sum << endl;
}