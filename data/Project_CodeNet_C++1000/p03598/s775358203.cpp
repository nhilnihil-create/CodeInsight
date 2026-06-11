#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
   int N,K,x_i,S=0;
   cin >> N >> K;
    
     rep(i, N) {
       cin >> x_i;
       
        if(x_i > (K-x_i)){
          S += (K-x_i);
        }
        else{
          S += x_i;
        }
     }
     cout << 2*S << endl;
}