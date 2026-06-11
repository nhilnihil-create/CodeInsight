#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  char op;
  cin >>A >>op >>B;
  
  if(op == '+'){
    C = A + B; 
  }
  if(op == '-'){
    C = A - B; 
  }
  
  cout << C;
  
}