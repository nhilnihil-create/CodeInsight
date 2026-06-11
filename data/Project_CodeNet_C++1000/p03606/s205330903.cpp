#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N,l,s,A = 0;
  cin >> N;
  
  for (int i = 0;i < N;i++) {
    
    cin >> l >> s;
    
    A += s - l + 1;
  }
  cout << A << endl;
}
