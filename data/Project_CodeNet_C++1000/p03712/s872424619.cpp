#include <bits/stdc++.h>

 using namespace std;
 
 int main(){
     
   int x, y;
   string picture;

   cin>>x>>y;
  
   cout<<'#';
   
   for(int i=0;i<y;i++){
     cout<<'#';
   }
   cout<<'#'<<endl;
  
  
   for(int i=0;i<x;i++){
       cin>>picture;
       cout<<'#'<<picture<<'#'<<endl;
   }
 
   cout<<'#';
   for(int i=0;i<y;i++){
     cout<<'#';
   }
   cout<<'#'<<endl; 
   
   
   return 0;
    
 }
