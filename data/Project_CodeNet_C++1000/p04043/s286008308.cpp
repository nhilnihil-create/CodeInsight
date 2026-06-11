#include<iostream>
using namespace std;
int main(){
  int a[3];
  int d=0,e=0;
  
  for(int i=0;i<3;i++){
    cin>>a[i];
    if(a[i]==5)
      d++;
    else
      e++;
  }
  if(d==2&&e==1)
    cout<<"YES";
  else
    cout<<"NO";
  
  return 0;
}
