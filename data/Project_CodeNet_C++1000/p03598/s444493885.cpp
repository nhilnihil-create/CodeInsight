#include<iostream>


using namespace std;

int main(){
   int N,K;
   int sum =0;
 cin >> N >> K;
   for(int i=0;i<N;i++){
       int s;
       
       cin >> s;
       
       if(K>=2*s){
           sum=sum+2*s;
       }
       else{
           sum =sum +2*(K-s);
       }
   }
   cout <<sum<<endl;
}
  