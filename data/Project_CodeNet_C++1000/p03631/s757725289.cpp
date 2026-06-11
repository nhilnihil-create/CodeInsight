#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  cout << ((n/100 == n%10%10) ? "Yes" : "No") << endl;
}