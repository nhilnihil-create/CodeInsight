#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  
  vector<long long>a(3*N);
  for (int i = 0; i < 3*N; i++) {
    cin >> a.at(i);
  }
  
  sort(a.begin(), a.end());
  long long A = 0;
  for (int i = N; i < 2*N; i++) {
    A += a.at(i);
  }
  long long B = 0;
  for (int i = N; i < 3*N; i += 2) {
    B += a.at(i);
  }
  
  if (A > B){
    cout << A << endl;
  }
  else {
    cout << B << endl;
  }
}