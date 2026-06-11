#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >>a>>b>>c;
  
  
  bool ans=true;
  for(int i=1;;i++){
    if((a*i)%b==c){
      break;
    }
    if(i==1){
      d=(a*i)%b;
    }
    if(i!=1 && (a*i)%b==d){
      ans=false;
      break; 
    }
  }
  if(ans){
    cout << "YES" <<endl;
  }
  else{
    cout << "NO" <<endl;
  }
}
