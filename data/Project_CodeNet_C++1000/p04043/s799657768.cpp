#include <bits/stdc++.h>
using namespace std;

int main(void){
   
   int a,b,c,d=0,e=0;
   cin >> a >> b >> c;
   
   if(a == 5){
       d++;
   }
   else if(a == 7){
       e++;
   }
   
   if(b == 5){
       d++;
   }
   else if(b == 7){
       e++;
   }
   
   if(c == 5){
       d++;
   }
   else if(c == 7){
       e++;
   }
   
   
   if(d == 2 && e == 1){
        cout << "YES" <<endl;   
   }
   else{
       cout << "NO" <<endl;
   }
}