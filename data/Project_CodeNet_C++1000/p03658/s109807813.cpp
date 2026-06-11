#include <bits/stdc++.h>
using namespace std;

int main() {
  int i,j,n,k,tmp,add=0;
  int l[100];
  cin>>n>>k;
  for(i=0;i<n;i++){
    cin>>l[i];
  }
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(l[i]<l[j]){
        tmp=l[i];
        l[i]=l[j];
        l[j]=tmp;
      }
    }
  }
  for(i=0;i<k;i++){
    add+=l[i];
  }
  
  cout<<add<<endl;
}