#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  double N;
  double A;
  
  1<=N<=100;
  0<=A<=N*N;
  cin >> N;
  cin >> A;
  cout << (N*N)-A << endl;
}