#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  int nm=k;
  for(int i=2;i<=n;i++){
    nm*=(k-1);
  }
  cout<<nm<<endl;
}
 