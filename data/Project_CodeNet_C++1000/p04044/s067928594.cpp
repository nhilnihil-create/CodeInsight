#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,L;
  cin >> N >> L;
  vector<string> A(N);
  for(int i=0; i<N; ++i){
    cin >> A[i];
  }
  sort(A.begin(),A.end());
  for(int j=0; j<N; ++j) {
    cout << A.at(j);
  }
  cout << endl;
}