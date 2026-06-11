#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int W,a,b;
cin >> W >> a >> b;
  if(a>b){
  if (b+W >a){
    cout << '0' << endl;
  }
  else {
    cout << a-b-W << endl;
  }}
    else{
   if (a+W >b){
    cout << '0' << endl;
  }
  else {
    cout << b-a-W << endl;
  }
  }
  
  }
    
    


