#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string A;
    cin >>A;
    int N=0,W=0,S=0,E=0;
    for(int i=0;i<A.size();i++){
    if(A.at(i)=='N'){
        N++;
    }
    else if (A.at(i)=='W'){
        W++;
    }
    else if (A.at(i)=='S'){
        S++;
    }
    else if (A.at(i)=='E'){
        E++;
    }
    }
  if(S>=1&&N>=1){
      if(E==0&&W==0){
         cout <<"Yes"<<endl;
         return 0;
    }
    if(E>=1&&W>=1){
     cout <<"Yes"<<endl;
     return 0;
    }
    }
 else  if(E>=1&&W>=1){
    if(S==0&&N==0){
      cout <<"Yes"<<endl;
     return 0;
    } 
     if(S>=1&&N>=1){
      cout <<"Yes"<<endl;
     return 0;
    }      
    }
 else  if(S==0&&N==0){
     if(W>=1&&E>=1){
      cout <<"Yes"<<endl;
     return 0;
    }
     if(E==0&&W==0){
      cout <<"Yes"<<endl;
     return 0;
    } 
    }   
else  if(E==0&&W==0){
     if(S>=1&&N>=1){
      cout <<"Yes"<<endl;
     return 0;
    }
    if(N==0&&S==0){
      cout <<"Yes"<<endl;
     return 0;
    }     
 }
 cout <<"No"<<endl;    
 
}
 