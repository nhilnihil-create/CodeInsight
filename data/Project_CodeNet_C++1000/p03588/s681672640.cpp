#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i).first >> A.at(i).second;
  }  
  sort(A.begin(), A.end());
  cout << A.at(N-1).first+A.at(N-1).second << endl;
}
