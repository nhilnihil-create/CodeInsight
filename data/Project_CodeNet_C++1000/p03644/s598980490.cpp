#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int num = 0;
  while (pow(2, num + 1) <= N){
    num++;
  }
  
  int ans = pow(2, num);
  cout << ans << endl;
}