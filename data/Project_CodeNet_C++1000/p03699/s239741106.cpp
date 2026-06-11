#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,k=0,l=101;
  cin>>N;
  for(int i=0;i<N;i++){
    int j;
    cin>>j;
    k+=j;
    if(j%10!=0)
      l=min(l,j);
  }
  if(l==101)
    cout<<0<<endl;
  else if(k%10==0)
    cout<<k-l<<endl;
  else
    cout<<k<<endl;
}