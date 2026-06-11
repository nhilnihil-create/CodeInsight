#include <bits/stdc++.h>
using namespace std;
int main(){
  int K,T,m,n;cin>>K>>T;cin>>m;
  for(int i=1;i<T;i++){
    cin>>n;m=max(m,n);
  }
  cout<<max(0,2*m-K-1)<<endl;
}