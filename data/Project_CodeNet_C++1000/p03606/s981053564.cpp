#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A,B;
  cin >> N;
  
  int num=0;

  for (int i = 0; i < N; i++){
      cin >> A >> B;
    num += B-A+1;
  }
  
  cout << num << endl;
    
 
}