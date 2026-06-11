#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  vector<int> A(n);
  for(int &i:A)
    cin>>i;
  int j,k,l=100000000000000000;
  for(int a=0;a<2;a++){
    k=0,j=0;
    for(int i=0;i<n;i++){
      k+=A[i];
      if(((i+a)%2*2-1)*k<=0){
        j+=1+abs(k);
        k=(i+a)%2*2-1;
      }
    }
    l=min(l,j);
  }
  cout<<l<<endl;
}