#include<iostream>

using namespace std;

int main(void)
{
  int n; cin>>n;
  
  int a=n%10;
  int b=(n/10)%10;
  
  if((a==9)||(b==9)){puts("Yes");}
  else{puts("No");}
  
  return 0;
}