#include <bits/stdc++.h>
using namespace std;
 int main() {
int a,b,c;
   cin >> a>>b;
   int flag=0;
   if(a%3==0)flag=1;
   else if(b%3==0)flag=1;
   else if((a+b)%3==0)flag=1;
   
   if(flag==1) cout <<"Possible"<<endl;
   else if(flag==0)cout <<"Impossible"<<endl;

   }
   
