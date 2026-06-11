#include <iostream>

using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int x=a+b;
  int y=b+c;
  int z=c+a;
  if(x==c || y==a || z==b){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
  return 0;
}