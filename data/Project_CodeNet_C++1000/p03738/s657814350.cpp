#include <bits/stdc++.h>
using namespace std;
 
int main() {
   string A,B;
   cin >>A>>B;
   if(A.size()>B.size()){
       cout <<"GREATER"<<endl;
   }
   else if(A.size()<B.size()){
       cout <<"LESS"<<endl;
   }
   else{
      for(int i=0;i<A.size();i++){
     int a= A.at(i)- '0';
     int b = B.at(i)- '0';
     if(a>b){
       cout <<"GREATER"<<endl;
       return 0;
     }
     else if(a<b){
       cout <<"LESS"<<endl;
       return 0;
     }
      }
      cout <<"EQUAL"<<endl;
    }
   }
