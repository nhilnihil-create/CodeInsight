#include <bits/stdc++.h>
using namespace std;

int main() {
     int N, K;
     cin >> N >> K;
     vector<int> v(N);
     for (int i = 0; i < N;i++){
       cin >> v.at(i);
     }
     int d = 0;
     for (int i = 0; i < N; i++){
         if(v.at(i)<=K/2){
           d += 2 * v.at(i);
         }
         else{
           d += 2 * (K - v.at(i));
         }
     }
     cout << d << endl;
}
