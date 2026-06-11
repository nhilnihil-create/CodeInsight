#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, n[3];
  cin >> N;
  n[0] = N % 10;
  n[1] = ((N % 100) - n[0]) / 10;
  n[2] = (N - (n[0] + n[1])) / 100;
  if(n[0] == n[2])
    cout << "Yes" << "\n";
  else
    cout << "No" << "\n";
  return 0;
}
