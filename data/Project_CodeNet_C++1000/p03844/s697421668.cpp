#include<iostream>
#include<string>
using namespace std;
int main()
{
  int A,B;
  char C;
  cin>>A>>C>>B;
  if(C=='+'){
    cout<<A+B;
  }
  else if(C=='-'){
    cout<<A-B;
  }
}