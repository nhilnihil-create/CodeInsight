#include<bits/stdc++.h>
using namespace std;
int main(){
char a,b;
  cin>>a>>b;
  int sum=0;
  if(a=='D')
    sum++;
  if(b=='D')
    sum++;
  if(sum==1)
    cout<<'D'<<endl;
  else
    cout<<'H'<<endl;
  
  
   return 0;
}