#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){
  
 string O,E;
 cin>>O>>E;
 
 int o=O.size(),e=E.size();
 if(o==e){
   for(int i=0;i<o;i++){
     cout<<O[i]<<E[i];
   }
 }
 else{
   cout<<O[0];
   for(int i=0;i<e;i++){
     cout<<E[i]<<O[i+1];
   }
 }
 
}
