#include<iostream>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int min=a+b;
  min=(a+c<min?a+c:min);
  min=(b+c<min?b+c:min);
  cout<<min<<endl;
  return 0;
}
