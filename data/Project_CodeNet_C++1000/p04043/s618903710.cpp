#include<bits/stdc++.h>
using namespace std;
int main(){
  int a[3];
  for(int i=0;i<3;i++)
    cin>>a[i];
  if(count(a,a+3,5) == 2 && count(a,a+3,7) == 1)
    cout<<"YES";
  else
    cout<<"NO";
  
}