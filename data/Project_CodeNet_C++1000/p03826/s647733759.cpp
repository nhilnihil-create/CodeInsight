#include<iostream>
using namespace std;
int main(){
int a,b,c,d;
  cin>>a>>b>>c>>d;
  long long int a1=a*b;
  long long int a2=c*d;
  cout<<max(a1,a2);
}