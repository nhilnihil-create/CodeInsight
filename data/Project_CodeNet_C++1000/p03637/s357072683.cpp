#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,z,i,o=0,f=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>z;
    if(z%2==1) o++;
    else if(z%4==0) f++;
  }
  if(o<=f) cout<<"Yes"<<endl;
  else if(o+f==n&&f==o-1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}