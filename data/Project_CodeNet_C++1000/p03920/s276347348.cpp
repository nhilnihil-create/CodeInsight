#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int i;
  for(i=1;i*(i+1)/2<N;i++){}
  if(i*(i+1)/2==N)for(int j=1;j<=i;j++)cout<<j<<endl;
  else{
    int k=i*(i+1)/2-N;
    for(int j=1;j<=i;j++){
      if(j!=k)cout<<j<<endl;
    }
  }
}
