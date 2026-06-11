#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int N,K,X,Y,sum = 0;
   cin >> N >> K >> X >> Y;
   for(int i=1;i<=N;i++){
       if(i <= K){
           sum+=X;
       }
       else{
           sum+=Y;
       }
   }
cout << sum <<endl;
}