#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> btn(N); 
 
  for (int i = 0; i < N; i++) {
    cin >> btn.at(i);
  }
  
  int Cbtn = 1;
  int cunt = 0;
  for (int i=0; i < N + 3 ; i++){
     if(btn.at(Cbtn-1) == 2){
        cunt++;
        break;
     }
     else{
     Cbtn = btn.at(Cbtn-1);
     cunt++;
     }
     if(i == N+2){
        cunt = -1;
        break;
     }
  } 
  cout << cunt << endl;
}
