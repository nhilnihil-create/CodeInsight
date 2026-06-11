#include <bits/stdc++.h>
using namespace std;

int main()
{
   int x,a,b;cin>>x>>a>>b;
   if(b-a>0){
       if(b-a>x){
           cout<<" dangerous ";
       } else {
           cout<<" safe ";
       }
   } else{
       cout<<" delicious ";
   }
   return 0;
}