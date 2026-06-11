#include<bits/stdc++.h>
using namespace std;

int main(void){
   int X,A,B;
   cin>>X>>A>>B;
   if(B-A<=0){
      cout<<"delicious"<<endl;
   }else if(B-A>=X+1){
      cout<<"dangerous"<<endl;
   }else{
      cout<<"safe"<<endl;
   }
   return 0;
}

