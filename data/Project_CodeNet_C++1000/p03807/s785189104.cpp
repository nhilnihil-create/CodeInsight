#include <bits/stdc++.h>
using namespace std;
int main(){
   int N;
   cin>>N;
   int ans = 0;
   for(int i = 1;i<=N;i++){
       int A;
       cin>>A;
       if(A%2==1){
           ans++;
       }
    }
   if((ans)%2==0){
       cout<<"YES"<<endl;
   }else{
       cout<<"NO"<<endl;
   }
}
       
