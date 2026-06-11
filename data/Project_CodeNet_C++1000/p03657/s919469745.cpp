#include<iostream>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  if(a%3==0){
    cout<<"Possible";
  }
  else{
    if(b%3==0){
      cout<<"Possible";
    }
    else if((a+b)%3==0){
      cout<<"Possible";
    }
    else{
      cout<<"Impossible";
    }
  }
}
