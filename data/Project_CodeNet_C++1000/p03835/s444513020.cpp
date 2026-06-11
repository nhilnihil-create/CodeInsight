#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int K, S;
   cin >> K >> S;
   int z, count = 0;
   for(int x=0; x<=K; x++) {
      for(int y=0; y<=K; y++) {
         z = S - x - y;
         if(z <= K && z >= 0) {
            count++;
         }
      }
   }
   cout << count << endl;
}