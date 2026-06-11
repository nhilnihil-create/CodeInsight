#include <bits/stdc++.h>
using namespace std;
int Dis(int x,int k){
    
    return 2*min(x,k-x);
}

int main(void){
   
   int N,K,x,ans=0;
   cin >> N >> K;
   
   for(int i=0;i<N;i++) {
       cin >> x;
       ans += Dis(x,K);
   }
   cout << ans << endl;
}