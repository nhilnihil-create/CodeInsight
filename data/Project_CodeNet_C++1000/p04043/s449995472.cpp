#include<iostream>
using namespace std;
int main(){
int a[3];
  int cf=0,cs=0;
  for(int i=0;i<3;i++)
  {
  	cin>>a[i];
    if(a[i]==5)
      cf++;
    if(a[i]==7)
      cs++;
  }
  if(cf==2 && cs==1)
    cout<<"YES";
  else
    cout<<"NO";
}