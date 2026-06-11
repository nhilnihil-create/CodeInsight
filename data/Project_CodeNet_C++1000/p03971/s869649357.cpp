#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  
  int x =0;
  int y =0;
  
  for(int i=0;i<N;i++){
    char z;
    cin>>z;
    
    if(z=='a'){
      if(x<A+B){
        x++;
        cout << "Yes"<<endl;
      }
      else{
        cout<<"No"<<endl;
      }
    }
    if(z=='b'){
      y++;
      if(x<A+B && y<=B){
        x++;
        cout <<"Yes"<<endl;
      }
      else{
        cout <<"No"<<endl;
      }
    }
    if (z=='c'){
      cout <<"No"<<endl;
    }
  }
}