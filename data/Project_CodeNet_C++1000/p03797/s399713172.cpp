#include<bits/stdc++.h>
using namespace std;
int main(){
  long n,m;cin>>n>>m;
  m/=2;
  cout<<(n>m?m:(m-n)/2+n);
}  