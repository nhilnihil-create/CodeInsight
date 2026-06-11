#include<iostream>
using namespace std;
int main(){
  int a,b,c;cin>>a>>b>>c;
  if(b>=c)cout<<"delicious\n";
  else if(b-c+a<0)cout<<"dangerous\n";
  else cout<<"safe\n";
}