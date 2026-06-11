#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
   long long A,B,C,_A,_B,_C,i;
   cin >> A >> B >> C;
   i = 0;
   while(A%2==0 && B%2==0 && C%2==0){
      if(A==B && B==C){
         cout << -1 << endl;
         return 0;
      }
      i++;
      _A = A;
      _B = B;
      _C = C;
      A = (_B+_C)/2;
      B = (_A+_C)/2;
      C = (_A+_B)/2;
   }
   cout << i << endl;
   return 0;
}