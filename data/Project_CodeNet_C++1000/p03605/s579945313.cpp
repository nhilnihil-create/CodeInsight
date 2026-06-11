#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  int n[2];
  bool ans = false;
  cin >> N;
  n[0] = N % 10;
  n[1] = (N - n[0]) / 10;
  if(n[0] == 9 || n[1] == 9)
    ans = true;
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
