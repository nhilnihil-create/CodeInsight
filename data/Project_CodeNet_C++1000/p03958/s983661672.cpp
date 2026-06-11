#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,T;
  cin>>K>>T;
  int k=0;
  for(int i=0;i<K;i++){
    int j;
    cin>>j;
    k=max(j,k);
  }
  cout<<max((k-(K/2)-1)*2+(K+1)%2,0)<<endl;
}