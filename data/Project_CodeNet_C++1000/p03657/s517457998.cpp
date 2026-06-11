#include <bits/stdc++.h>
using namespace std;
int main(){
 int A,B;
 cin>>A>>B;
 int a=A+B;
 if(A%3==0){
     cout<<"Possible"<<endl;
 }
 
 else if(B%3==0){
     cout<<"Possible"<<endl;
 }
 
 else if(a%3==0){
     cout<<"Possible"<<endl;
 }
 
 else{
     cout<<"Impossible"<<endl;
 }
 
}