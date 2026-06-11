#include <bits/stdc++.h>
using namespace std;

int main() {
  int A , B , C , D ;
  cin >> A >> B >> C >> D ;
  
  int E = A * B ;
  int F = C * D ;
  
  if(E > F){
    cout << E << endl;
  }
  else if (E == F){
    cout << E << endl;
  }
  else if (E < F){
    cout << F << endl;
  }  
}
