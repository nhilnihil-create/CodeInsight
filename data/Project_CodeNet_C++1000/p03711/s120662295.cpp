#include<bits/stdc++.h>
using namespace std;
int main(){
  int A; int B; cin>>A>>B;
  if(A==2){
    if(B==2)
      cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else if(A==4||A==6||A==9||A==11){
    if(B==4||B==6||B==9||B==11)
      cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  else{
    if(B==1||B==3||B==5||B==7||B==8||B==10||B==12)
      cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}