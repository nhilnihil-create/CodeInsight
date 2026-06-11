#include <bits/stdc++.h>
using namespace std;

int main() {
  long int N;
  cin >> N;
  
  vector<long int> A(3*N);    
  for (int i = 0; i < 3*N; i++) {
    cin >> A.at(i);
  }
  
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  
  long int sum = 0;

  for (int i = 1; i <= N; i++) {
    sum = sum + A.at(2*i-1);
  }  
   
  cout << sum << endl;
    
}