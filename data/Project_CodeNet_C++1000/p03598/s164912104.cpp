#include <bits/stdc++.h>
using namespace std;

int main() {
    
    
  int N , A , C, D =0 ;
  cin >> N >> A;
  
  for (int i = 0; i < N; i++) { 

    int B;
    cin >> B ;
    
    C =( A - B)*2;
    
    
	if (B * 2 <= C) {
      D += B*2 ;

      
    }
    else if (B * 2 > C){
      D += C ;

    }

  }

  cout << D << endl;

}
