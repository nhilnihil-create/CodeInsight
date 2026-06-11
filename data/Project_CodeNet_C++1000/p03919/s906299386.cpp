#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  vector<vector<char>>C(a,vector<char>(b*5,0));
  for(int i=0;i<a;i++){
    for(int j=0;j<b*5;j+=5){
      cin>>C[i][j]>>C[i][j+1]>>C[i][j+2]>>C[i][j+3]>>C[i][j+4];
      if(C[i][j]=='s'){
        if(C[i][j+1]=='n'){
          if(C[i][j+2]=='u'){
            if(C[i][j+3]=='k'){
              if(C[i][j+4]=='e'){
                cout<<char(j/5+65)<<i+1<<endl;
                break;
              }
            }
          }
        }
      }
    }
  }
}