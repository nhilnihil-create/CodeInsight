#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int odd_count = 0;
  int a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if(a % 2) odd_count++;
  }
  
  if (odd_count % 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
 
}