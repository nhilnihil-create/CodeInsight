#include <bits/stdc++.h>
using namespace std;

int main() {
  int W,H;
  cin>>H>>W;
  for(int i=0;i<H+2;i++){
    if(i==0||i==H+1){
      for(int j=0;j<W+2;j++){
        cout<<"#";
      }
    }else{
      for(int j=0;j<3;j++){
        if(j==0||j==2){
          cout<<"#";
        }else{
          string st;
          cin>>st;
          cout<<st;
        }
      }
    }
    cout<<endl;
  }
}
          
  
  
  
  
 
  
 
  

