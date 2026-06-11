#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(A.begin(), A.end());
  
  long long yi = 0;
  for(int i = 0; i < N; i++){
    if((A[i].second ^ i) & 1) ++yi;
  }
  
  cout << (yi >> 1) << endl;
  
  return 0;
}