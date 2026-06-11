#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N ;
  int P = 0; 
  
  for (int i = 0;i < N; i++) {
   
   int l_i,r_i;
     
    cin >> l_i >> r_i;
    
   P  += r_i - l_i + 1;
  }
  cout << P << endl;
}