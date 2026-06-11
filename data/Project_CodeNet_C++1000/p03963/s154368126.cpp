#include <bits/stdc++.h>
using namespace std;

 int main(){
   int N,K;
   cin >> N >> K;
   int s = K;
   for (int i = 0; i < N - 1; i++) {
     s *= (K - 1);
   
   }
     cout << s;
 
 }
