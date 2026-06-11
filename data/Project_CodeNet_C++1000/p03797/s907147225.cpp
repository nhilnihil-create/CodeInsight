#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,m; cin>>n>>m;
  long long res=0;
  if(n*2<=m){
    res+=n;
    m-=n*2;
    res+=m/4;
  }else{
    res+=m/2;
  }
  cout<<res<<endl;
}