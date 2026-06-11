#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N , K, X , total;
  cin >> N >> K;
  total = 0;
  for( int i = 0; i < N; i++ ){
    cin >> X;
    if( X * 2 > ( K - X ) * 2 ){
      total += ( K - X ) * 2;
    }
    else{
      total += X * 2;
    }
  }
  cout << total << endl;
}