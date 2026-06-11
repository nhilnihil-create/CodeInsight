#include<bits/stdc++.h>
using namespace std;

int main(){
  int X,A,B;
  cin>>X>>A>>B;
  
  if(B-A>X){
    cout<<"dangerous"<<endl;
  }
  else if(B>A &&B-A<=X){
    cout<<"safe"<<endl;
  }
  else{
    cout<<"delicious"<<endl;
  }
}
    
