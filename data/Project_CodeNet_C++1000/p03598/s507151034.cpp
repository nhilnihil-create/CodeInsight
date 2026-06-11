#include <bits/stdc++.h>
using namespace std;
int main(){
 int N;
  cin >> N;
  int K;
  cin >> K;
  int X;
  int Goukei = 0;
   for(int i = 0; i < N; i++){
     cin >> X;
    if( X * 2 < ( K - X ) * 2 ){
      Goukei +=  X * 2;
    }
     else{
       Goukei += ( K - X ) * 2;
     }
   }
  cout << Goukei << endl;
}