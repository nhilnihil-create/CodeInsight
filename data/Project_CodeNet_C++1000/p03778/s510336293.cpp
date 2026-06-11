#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
  int w,a,b; cin>>w>>a>>b;
  int s=abs(a-b);
  
  if(w<=s){cout<<s-w<<endl;}
  else{puts("0");}
  
  return 0;
}