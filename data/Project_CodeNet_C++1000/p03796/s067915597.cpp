#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
   long N,power=1;
   int i;
   cin>>N;
   long E=pow(10,9)+7;

   for(i=2;i<=N;i++){
    power*=i;
    if(power>=E) power%=E;
   }

   cout<<power<<endl;
    return 0;
}
