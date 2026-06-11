#include<iostream>
using namespace std;
int main(){
  int a,b,kaunto=0;
  cin>>a>>b;
  if(a>0)
    cout<<"Positive"<<endl;
  else if(a==0||b==0||(a<0&&b>0))
    cout<<"Zero"<<endl;
  else if(b<0){
    for(int i=a;i<=b;i++){
      kaunto++;
    }
    if(kaunto%2==0)
      cout<<"Positive"<<endl;
    else
      cout<<"Negative"<<endl;
  }
  
  return 0;
}