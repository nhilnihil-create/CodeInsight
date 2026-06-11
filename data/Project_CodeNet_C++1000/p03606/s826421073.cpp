#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B=0;
  cin >> N;
  
  
  for (int i = 0; i < N  ; i++) {
		
    int m,l;
    cin >> m >> l ;
    
    A = l-m +1;
    B = A + B ;
  }
    
    
    

  cout << B << endl;
}
