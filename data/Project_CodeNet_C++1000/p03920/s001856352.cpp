#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c=0,i=1;
  cin>>n;
  while(n>c){
    c+=i;
    i++;
  }
  i--;
  c-=i;
  if(c==n){
    for(int j=1;j<i;j++){
      cout<<j<<endl;
    }
  }else{
    c+=i;
    int k=c-n;
    for(int j=1;j<=i;j++){
      if(j==k)
        continue;
      cout<<j<<endl;
    }
  }
}