#include<bits/stdc++.h>
using namespace std;

int main(){
  int X,A,B;
  cin>>X>>A>>B;
  if(A-B>=0){
    cout<<"delicious"<<endl;
    return 0;
  }
  if(A-B+X>=0){
    cout<<"safe"<<endl;
    return 0;
  }
  cout<<"dangerous"<<endl;
  return 0;
}

      
    

