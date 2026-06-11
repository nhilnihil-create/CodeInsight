#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i =0; i<N; i++)cin >> A.at(i);
  
  vector<int>B(100011);
  for(int i=0; i<N; i++){
    B.at(A.at(i)) ++;
    B.at(A.at(i)+1) ++;
    B.at(A.at(i)+2) ++;
  }
  
  sort(B.begin(), B.end());
  cout << B.at(100010) << endl;
  
}