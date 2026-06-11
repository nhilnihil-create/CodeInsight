#include <bits/stdc++.h>
using namespace std;

int main() {

  int A;
  cin >> A;
  
  char op;
  cin >> op;
  
  int B;
  cin >> B;
  
  int ans;
  
  if (op=='+'){
  	ans = A + B;
  }
  
  if (op=='-'){
  	ans = A - B;
  }
  
  cout << ans << endl;
}

