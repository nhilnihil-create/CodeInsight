#include<iostream>

int main(){
  int a,b;
  std::cin>>a>>b;
  if(a==2||b==2){
    std::cout<<"No"<<std::endl;
  }
  else if((a==4||a==6||a==9)&&(b==6||b==9||b==11)){
    std::cout<<"Yes"<<std::endl;
  }
  else if((a==1||a==3||a==5||a==7||a==8||a==10||a==12)&&(b==1||b==3||b==5||b==7||b==8||b==10||b==12)){
    std::cout<<"Yes"<<std::endl;
  }
  else std::cout<<"No"<<std::endl;
  return 0;
}

