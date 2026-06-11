#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a = 0;
  cin >> N;
  vector<int> A(N);
  
  for(int i = 0; i < N; i++)
    cin >> A.at(i);
  
  int i = 0;
  for(;1;){
    if(a == 1){
      cout << i << endl;
      break;
    }
    a = A.at(a) - 1;
    if(i >= N){
      cout << -1 << endl;
      break;
    }
    i++;
  }
}