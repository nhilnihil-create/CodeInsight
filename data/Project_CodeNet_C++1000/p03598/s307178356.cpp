#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,K,X,L;
  cin >> N >> K;
X=1;
L=0;
  for( int i=0; i < N; i++){
    cin >> X;
    if(2*X <= K){
      L += 2*X;}
    else{
      L += 2*K-2*X;}  
  }
 cout << L << endl;
}