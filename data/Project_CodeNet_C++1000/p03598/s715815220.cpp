#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, P, D, Q;
  cin >> N >> K;
  P=1;
  Q=0;
 while(N-P>=0){
   cin >> D ;
   if( D<= K/2){
     Q=Q+(D*2);
   P++;
   }
   else if( D>K/2){
     Q=Q+(K-D)*2;
     P++;
   }
 }
  cout << Q <<endl;
}
