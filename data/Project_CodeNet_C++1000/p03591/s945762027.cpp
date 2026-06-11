#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
long input(){
  long x;
  cin>>x;
  return x;
}
int abs(int x){
  if(x>=0){
    return x;
  }else{
    return -x;
  }
}
int gcd(int x, int y){
	if(x<y){
    return gcd(y,x);
  }
  if(y==0){
    return x;
  }
  return gcd(y,x%y);
}



int main() {
  string S;
  cin>>S;
  if(S.size()>=4){
    if(S.at(0)=='Y'&&S.at(1)=='A'&&S.at(2)=='K'&&S.at(3)=='I'){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else{
    cout<<"No"<<endl;
  }





  
  
}

 



  
  
  
