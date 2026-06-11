#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   int N,M,A,B;
   cin >> N >> M;
   int city[N];
   for(int i=0;i<N;i++) city[i] = 0;
   
   for(int i=0;i<M;i++){
       cin >> A >> B;
       city[A-1]++;
       city[B-1]++;
   }
   
   for(int i=0;i<N;i++) cout << city[i] << endl;
}