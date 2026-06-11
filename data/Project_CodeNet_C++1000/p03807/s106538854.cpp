#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,j=0;
  cin>>N;
  while(N--){
    int A;
    cin>>A;
    if(A%2==1)
      j++;
  }
  if(j%2==0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}