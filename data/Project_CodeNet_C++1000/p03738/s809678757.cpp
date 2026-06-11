#include<bits/stdc++.h>
using namespace std;

int main(void){
   string A,B;
   cin>>A>>B;
   if(A.size()==B.size()){
      if(A[0]>B[0]) cout<<"GREATER"<<endl;
      else if(A[0]<B[0]) cout<<"LESS"<<endl;
      else cout<<"EQUAL"<<endl;
   }else if(A.size()>B.size()){
      cout<<"GREATER"<<endl;
   }else{
      cout<<"LESS"<<endl;
   }
   return 0;
}

