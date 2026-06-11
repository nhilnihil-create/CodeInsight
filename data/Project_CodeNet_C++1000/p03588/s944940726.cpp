#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  vector<int>B(N);
  int MaxA = 0;
  int Max;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    if (MaxA < A.at(i)){
      MaxA = A.at(i);
      Max = A.at(i) + B.at(i);
    }
  }
  cout << Max << endl;
}

