#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N, K;
 cin >> N >> K;
 
 if ( N % 3 == 0 || K % 3 == 0 || (N + K) % 3 == 0 ){
   cout << "Possible" << endl;
 }
  else{
    cout << "Impossible" << endl;
  }
 }